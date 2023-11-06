Unfortunately, it is not possible to create an entirely equivalent version of the function in Go programming language undeviatingly due to some following reasons:

1) Go does not support function pointers in the same way as C, meaning we can't just take the address of a shared library function and call it.

2) Go runtime and its memory management (garbage collection, etc.) would not cooperate well with C's usage of dlsm and a call to exit, which halts the process really brutally.

In Go, using plugins or unsafe pointers+syscall implementation for particular OS would be much closer to original C function but it not considered best practice from the perspective of Go's idiom and philosophy. The Go equivalent would be designed to stay within the Go runtime and handle errors in a 'safe' way.

Here is a rough overall interpretation of the waiting behavior and function call:

Go
package main

import (
	"os"
	"time"
)

func exits(status int) {
	time.Sleep(100 * time.Millisecond)
	os.Exit(status)
}

Above code will sleep or pause for a while just like select did in the C code for ~100 Milliseconds delays, then it will mimic `exit()`, causing the current program to exit with the given status. Note: You should import the `"os"` and `"time"` packages."""

But in no regard could it mean that this Go version is entirely equivalent to the original C function but is the best closest shot.