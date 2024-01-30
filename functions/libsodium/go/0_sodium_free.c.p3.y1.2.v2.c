Assuming that some missing functions such as `_unprotected_ptr_from_user_ptr()`, `_mprotect_readwrite()`, `_out_of_bounds()`, `sodium_munlock()`, `_free_aligned()` in the given C implementation above are available globally and the convenient replacements or equivalents are available and correctly defined in the target language (Go in this case) environment which is exceptionally unlikely due to them not being standard function. Otherwise, you need to implement these functionalities by yourself. Anyway, below is the raw conversion directly translated these functionalities with same structure logic and appropriates conversion factor.
go
package main

import (
	"unsafe"
)

func sodium_free(ptr unsafe.Pointer) {

        const (
	     page_size        = 4096
	     sizeof_canary    = 4
	)
	var base_ptr uintptr
	var canary_ptr uintptr
	var unprotected_ptr uintptr
	var total_size uintptr
	var unprotected_size int

        var canary unsafe.Pointer
	

	if ptr == nil {
		return;
	}
        canary_ptr  = uintptr(ptr) - sizeof_canary 
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr) // presuming that the function accepts an unsafe.Pointer
        base_ptr   	= unprotected_ptr - page_size * 2 
	         
        memcpy(&unprotected_size, unprotected_ptr, unsafe.Sizeof(unprotected_size)) // presuming `memcpy` either globaly figured out or is apart of other the imported library
        total_size = page_size + page_size + uintptr(unprotected_size) + page_size
	         
        _mprotect_readwrite(base_ptr, total_size)
	if sodium_memcmp(canary_ptr, canary, sizeof_canary) != 0 {
		_out_of_bounds();
	}
 
	if sodium_memcmp(unprotected_ptr + uintptr(unprotected_size), canary, sizeof_canary) != 0 {
		_out_of_bounds();
	}

	sodium_munlock(unprotected_ptr, uintptr(unprotected_size))
	_free_aligned(base_ptr, total_size)

}

func main() {
	var pointer unsafe.Pointer
	sodium_free(pointer)
}
