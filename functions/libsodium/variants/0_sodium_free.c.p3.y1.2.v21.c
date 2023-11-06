Here's a semantically equivalent version of your `sodium_free` function in Go. Note that given the signature of the original C function, it seems to be related specifically to thelibsodium library (secure memory management). Ensure you port all necessary low-level components for it to work if not seeking higher-level APIs:

go
import (
	"bytes"
	"unsafe"
)

func sodium_free(ptr unsafe.Pointer) {

	var base_ptr *byte
	var canary_ptr *byte
	var unprotected_ptr *byte
	var total_size uintptr
	var unprotected_size uintptr

	if ptr == nil {
		return
	}
	canary_ptr = ((*byte)(ptr)) - unsafe.Sizeof(canary)
	unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr)
	base_ptr = unprotected_ptr - page_size * 2
	unprotected_size = uintptr(*base_ptr)
	total_size = page_size + page_size + unprotected_size + page_size

	_mprotect_readwrite(base_ptr, total_size)

	if bytes.Compare((*[unsafe.Sizeof(canary)]byte)(unsafe.Pointer(canary_ptr))[:], canary[:]) != 0 {
		_out_of_bounds()
	}

	if bytes.Compare(((*[unsafe.Sizeof(canary)]byte)(unsafe.Pointer(uintptr(unsafe.Pointer(unprotected_ptr)) + unprotected_size)))[:], canary[:]) != 0 {
		_out_of_bounds()
	}

	sodium_munlock(uintptr(unsafe.Pointer(unprotected_ptr)), unprotected_size)
	_free_aligned(uintptr(unsafe.Pointer(base_ptr)), total_size)
}


Remember: with Go, you don't have as much hands-on access to the memory as with C, this could potentially break the Direct Memory Access (DMA). 

Hardcoding the memory size may not always be a good idea. Page size may vary per system, for exact value you may have to call an OS function.

This function works directly manipulating memory addresses, which is rarely needed in Go. High-level wrappers are usually preferred. More over underlying layers could've performed these checks already (bounds checks, mem protection, etc). Using types those boundaries are dictated at compile time would prevent a lot of headaches that raw pointers impose.

Bear in mind that Go's garbage collection kind of gets in the way of "Secure deletion" which is aimed with these libraries are meant to circumvent. Because the GC moves values around in memory and leaves old copies around which can leak secure data. If this level of security is needed, it is probably fine to just call cgo or write a weird specialized bit in C. 

It should be noted if you want to experiment or fine tune for integrating existing systems, you will have to give great consideration towards error handling and correct boundary checks for the systems.
