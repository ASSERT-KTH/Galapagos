The implementation in Go could look like this:

go
import (
	"C"
	"reflect"
	"unsafe"
)

func sodium_free(ptr unsafe.Pointer) {
	if ptr == nil {
		return
	}

	canary_size := (int)(unsafe.Sizeof(canary))
	unprotected_ptr := unprotected_ptr_from_user_ptr(ptr)

	prot_page_size := (1 << 12) // page size = 4096

	base_ptr := uintptr(unprotected_ptr) - uintptr(prot_page_size)*2

	unprotected_size_ptr := (*int)(unsafe.Pointer(base_ptr))
	unprotected_size := reflect.Indirect(reflect.NewAt(reflect.TypeOf(unprotected_size_ptr).Elem(), unsafe.Pointer(base_ptr))).Interface().(int)

	total_size := prot_page_size*2 + unprotected_size + prot_page_size
	set_mprotect_readwrite(unsafe.Pointer(base_ptr), uintptr(total_size))

	unprot_slice := C.GoBytes(unsafe.Pointer(uintptr(ptr)-uintptr(canary_size)), C.int(canary_size))
	canary_slice := C.GoBytes(unsafe.Pointer(&canary), C.int(len(canary)))

	if !bytes.Equal(unprot_slice, canary_slice) {
		_out_of_bounds();
	}

	no_prot_canary := C.GoBytes(unsafe.Pointer(unprotected_ptr + uintptr(unprotected_size)), C.int(canary_size))

	if !bytes.Equal(no_prot_canary, canary_slice) {
		_out_of_bounds()
	}

	sodium_munlock(unsafe.Pointer(unprotected_ptr), uintptr(unprotected_size))

	free_aligned(base_ptr, uintptr(total_size))
}


Details which needs an attention:
1. Into Go implementation C and reflect native packages are used. 
2. `GoBytes(...)` conversion from c-array to go-slice is adapted.
3. Page size for unix-based server side generally is 4 Kb, that equals 2^12, so the const is 1 << 12.
4. There is no mutex or write flag protections system in go like `mprotect` in C, let's assume a described function `set_mprotect_readwrite(...)`.
5. Also, there're been implemented an auxiliary functions, which identities are `_out_of_bounds()`, `sodium_munlock(...)`, and `free_aligned(...)`. They are presented in the C implantation, so, they should be described as singletons functs inside a Go env.
6. To maintain the function signature, all types which has presented as pointers inside the C func should be presented as 'unsafe.Pointer' inside the golang.

Assumption:
1. Because canary seems like a constant or a variable defined out of scope, it should have either a pointer reference to an initialized c-array typed variable, or be enumerated like a param in sodium_free func().
2. Page size vary across different environments. In most Unix-like systems, it is either 4096, or 8192 bytes (and note that it can change across kernel versions). The mentioned value (4096) generally consistent for most server runtimes and 'localhost' systems. Please, check it to make make certain which one the sys requires (fyi, there is a system's fd to catch up a definite size `os.Getpagesize()`).
3. It's hard to judge about unprotected_ptr_from_user_ptr(ptr). Sorry for no advice to be given at this point!