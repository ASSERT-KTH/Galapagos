go
func ldbBufferClear(z *LdbBuffer) {
	if z.alloc > 0 {
		free(z.data)
	}
	
	z.data = nil
	z.size = 0
	z.alloc = 0
}


Please note that memory management in Go is handled by garbage collector, no direct user-related method for free operation on pointer data. You just assign `nil` to the pointer and the garbage collector automatically frees the memory when there are no references to it anymore. 

This function `free(z.data)` would have to be supplied by the whatever package is used, as `free` function is not part of the Go language.