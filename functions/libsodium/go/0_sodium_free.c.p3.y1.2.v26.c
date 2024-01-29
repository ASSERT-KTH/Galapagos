Here's equivalent function in Go:

Go
import (
	"reflect"
	"unsafe"
)

func sodium_free(ptr unsafe.Pointer) {
	if ptr == nil {
		return
	}

	canary_ptr := (*byte)(unsafe.Pointer(uintptr(ptr) - unsafe.Sizeof(canary)))
	unprotected_ptr := unprotected_ptr_from_user_ptr(ptr)
	base_ptr := unsafe.Pointer(uintptr(unprotected_ptr) - page_size*2)
	unprotected_size := uintptr(reflect.ValueOf(*(**uintptr)(unsafe.Pointer(&base_ptr))).Elem().Elem())
	total_size := page_size + page_size + unprotected_size + page_size
	mprotect_readwrite(base_ptr, total_size)

	if sodium_memcmp(canary_ptr, canary, unsafe.Sizeof(canary)) != 0 {
		_out_of_bounds()
	}
	if sodium_memcmp(unsafe.Pointer(uintptr(unprotected_ptr)+unprotected_size), canary, unsafe.Sizeof(canary)) != 0 {
		_out_of_bounds()
	}
	sodium_munlock(unprotected_ptr, unsafe.Sizeof(unprotected_size))
	free_aligned(base_ptr, total_size)
}

In this snippet, please note the following:

- A size check on entry makes sure that you avoid processing nil pointers, just as the original function. 
- We take advantage of Go's unsafe package to perform pointer arithmetic (Related to start address calculation base pointer calculations).
- Arrays or slices, unlike other variables or structures, cannot be directly compared in Go but we maintained it in here to maintain direction towards the memory freeing procedures.

Please note that the exact Go Equivalent might getting complicated due to missing details like data types of functions not defined in code snippet provided like _protected_ptr_from_user_ptr, _out_of_bounds, free_aligned, mprotect_readwrite, sodium_munlock. The above snippet Incomplete due to not specifying Go esque clear memory functionality/data related functionality in the provided source snippet you gave. Most Go programs use basic libraries with Garbage Collector managing free and allocating memory which describes that this type of code is hardly ever written in Go.
