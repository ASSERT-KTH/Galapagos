Assuming "randombytes_init_if_needed()" and "implementation->buf" are some global functions. An equivalent Go code could be:

go
package main

import "unsafe"

func randombytesBuf(buf unsafe.Pointer, size uint) {
	randombytesInitIfNeeded()
	
	if size > 0 {
		implementationBuf(buf, size)
	}
}


In Go guarantees the existence of "unsafe", "uintptr" and its concurrency power. 
Please note that using "unsafe" is usually discouraged in Go, except in some unusual circumstances, and it sacrifices type safety. You should use caution when including it in your code, as it could harm portability and make it more difficult to maintain over time. You must as well make sure your "implementationBuf()" function properly checks for null pointers when adapting this logic, to avoid null pointer dereferencing or panic at runtime. These warnings are here precisely because not every construction transfers from C to Go in a 1-to-1 manner.  This is not necessarily C to Go conversion. This is pretty general status stands to have global function in converted way. If whole code is needed to get converted we might need more details for conversion or compilations error that would come across.