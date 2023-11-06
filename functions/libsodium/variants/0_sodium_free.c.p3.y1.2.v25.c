Due to Go's strongly typed nature and some language-specific constructs, it's impossible to make a direct 1:1 semantically equivalent translation. However, here is an attempt which focuses on memory deallocation, protecting data using canary variables and calling an out-of-bounds function if certain memory-check conditions fail. Note: the Go language operates under garbage collection environment so manual heap allocation and deallocation is not that optimized, but we could use third-party libraries like `golang.org/x/sys/unix` functions for syscalls.

First we need to ascertain the canary and page_size values.

go
var canary []byte // define as required
var page_size = os.Getpagesize()

func sodium_free(pointer unsafe.Pointer) {
	var (
	  	base_ptr, canary_ptr, unprotected_ptr []byte
		total_size, unprotected_size          uintptr
	)

	if pointer == nil {
		return
	}

	canary_ptr_bytes := uintptr(pointer) - unsafe.Sizeof(canary)
	canary_ptr := (*byte)(unsafe.Pointer(uintptr(canary_ptr_bytes)))

	unprotectedPointerBytes := uintptr(_unprotectedPtrFromUserPtr(pointer))
	unprotected_ptr = (*byte)(unsafe.Pointer(uintptr(unprotectedPointerBytes)))

	base_ptr_bytes := unprotectedPointerBytes - 2*uintptr(page_size)
	base_ptr := (*byte)(unsafe.Pointer(uintptr(base_ptr_bytes)))

	unprotected_size_mem := unsafe.Pointer(uintptr(base_ptr))
	unprotected_size_type := unsafe.Pointer((*uintptr)(unprotected_size_mem))

	copy(&unprotected_size, unprotected_size_type, unsafe.Sizeof(unprotected_size))

	total_size = uintptr(page_size + page_size + unprotected_size + page_size)
	
	// hand coding these functions due to lack of access to sodium_used functions.

	var sodium_unlock []byte // define sodium_unlock as required
	var sodium_memcmp []byte // define sodium_memcmp as required
	unix.Mprotect(base_ptr, total_size)
   	
	err := bytes.Compare(sodium_memcmp, canary)
   	if err != 0 {
	   	_outOfBounds()	   
	}

	unix.Madvise(unprotected_ptr, unprotected_size) 
	// represents sodium_munlock opcode MADV_DONTNEED in Go

	free_aligned(base_ptr, total_size)
	// represents _free_aligned function in Go
}
