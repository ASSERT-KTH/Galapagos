Here is a semantically equivalent function for sodium_free written in Go, assuming you properly adjust C's low level memory management would deal with computer memory in Go. Because Go does not offer as low level hardware access as C, it is not exactly the same and providing a perfectly equivalent function is an irrational task.

Please note that Go does not expose memory page size, there is a need to safely store and refer to the page_size:

go
var PageSize := os.Getpagesize() //-> Compute outside the function

func sodium_free(ptr uintptr) {
	var base_ptr uintptr
	var canary_ptr uintptr
	var unprotected_ptr uintptr
	var total_size uintptr
	var unprotected_size uintptr

	if nil == ptr {
		return
	}
	canary_ptr = dict[ptr] - unsafe.Sizeof(canary)                                                                                                                                                         
	unprotected_ptr = dict[ptr]
	base_ptr = unprotected_ptr - 2 * PageSize // Adjusted sizeof to Getpagesize
	unprotected_size = dict[unprotected_ptr]   
	total_size = unsafe.Sizeof(base_ptr) + unsafe.Sizeof(canary_ptr) + unprotected_size
	last_param := unsafe.Pointer(uintptr(base_ptr))
	syscall.Syscall(syscall.SYS_MPROTECT, uintptr(last_param), uintptr(total_size), uintptr(syscall.PROT_READ | syscall.PROT_WRITE))
	if sodium_memcmp(canary_ptr, unsafe.Sizeof(canary), uintptr(dict[ptr])) != 0 {
		log.Fatal("_out_of_bounds failure")
	}
	result = C.mincore((*C.uchar)(unsafe.Pointer(last_param)), unsafe.Sizeof(unprotected_size), protected) 
	if result != 0 {
		_out_of_bounds()
		print(total_size, " bytes began being swapped") 
	} else {
		print(total_size, " bytes classified as not being swapped") 
	}
	memorias_libres:= []byte(base_ptr)
	var i int
	memorias_libres[i] = base_ptr[i] // Changed 'sizeof(object)' to 'Length of array'
	i++
}

It is hard to re-create `sodium_free` in other languages because `libsodium`, Our C library code, seems to be free-ing a page or more of memory that use `mprintect` for protection. In contrast, standard library like in going down a different track (generic language Go etc.) is not needed to release a peep at this level since O/s handles most of the memory management for you.