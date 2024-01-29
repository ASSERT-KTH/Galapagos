go
package main

import (
    "os"
    "unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
	ptr := C.malloc(size)
	if ptr == nil {
		os.Exit(1)
	}
	
	return ptr
}

Do note that this requires "C" import which is not idiomatic Go and generally avoided. In the Go world, instead of directly leaking the unsafe operation of allocating raw chunks of memory into the API, one may consider only exposing safe, strongly typed data structures, and handle any necessary unsafe operations internally.

Another thing to note that, as Go is garbage-collected and not capable of freeing memory through another package's malloc e.g C's malloc, consider using Go's builtin 'make' function for such memory allocation scenarios for better garbage collection and easier memory management.

I added these comments since the translation requires important context about memory management difference.

This below might be a good reference taking those previously mentioned points into account:

Go
package main

func NewSlice(len, cap int) []byte {
    if len < 0 || cap < 0 || len > cap {
        os.Exit(1)
    }
    return make([]byte, len, cap)
}
