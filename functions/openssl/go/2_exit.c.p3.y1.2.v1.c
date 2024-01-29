This is a difficult task to accomplish because Go and C have very different philosophy in handling low-level system tasks. Most importantly, exit and delay mechanism (which select and dlsym accomplish in C) are managed differently in Go.

Below is a conceptual route towards an equivalently-functioning Go implementation, keeping the key functionalities of the given C code - load dynamic shared library, delay and exit.

go
package main

import (
	"C"
	"os"
	"time"
	"syscall"
	"unsafe"
)

//export myexit
func myexit(status C.int) {
	delay := 100 * time.Millisecond // equivalent of delaying for tv.tv_usec = 100000 microseconds
	time.Sleep(delay)
	os.Exit(int(status))
}


To use this, you need a .so C dynamic library with the reference to the Go relay function.

Making a true one-to-one translation of the code you provided from C to Go simply just isn't feasible. Go doesn't manage libraries the same way C does and select is a keyword in Go used for channel-based workflows, not a pausing method. There is also no RDLD_NEXT equivalent in Go.