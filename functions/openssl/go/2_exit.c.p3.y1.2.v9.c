Go's "os" package provides an Exit() function for terminating the program, and "time" package to generate the delay similar to the C code. However, Go does not have an exact equivalent to dlsym function used in C for finding the memory address of a symbol, in this case 'exit'. Here is the Go translation that comes closest to the C function:

Go
package main

import "os"
import "time"

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}

But please understand, that Go isn't the best equivalent for C on this, it gives many high-level constructs for working with, like goroutines for asynchronous jobs and flexible error management.