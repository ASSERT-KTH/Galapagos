go
package main

import "os"

func btcMalloc(size int) []byte {
    ptr := make([]byte, size)
    if ptr == nil {
        os.Exit(1)
    }
    return ptr
}


Notice a few core differences:

1. Go uses `make` for memory allocation instead of `malloc`, which is used in C.
2. Each `make` call in `Go` also initialize the memory (opposite to `malloc`).
3. Go uses `os.Exit` to terminate the program, equivalent to `abort` in C.
4. C does not provide built-in size for primitives. Thus, `size_t` is used, which specifies the number of bytes. However, in Go, we declare the number of elements directly. Thus, `int` type is more appropriate in the Go function. 

That makes the code more or less equivalent but it may behave ever so slightly differently in specific scenarios because C and Go treat memory a bit differently.