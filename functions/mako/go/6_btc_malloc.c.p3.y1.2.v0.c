You can use `panic` to crash the program as `abort()` does in C. The `panic` function in Go provides functionality similar to abort in C, where the execution is stopped immediately.

Here is the equivalent version in Go:

go
package main

import (
    "os"
)

func BtcMalloc(size int) []byte {
    if size < 0 {
        panic("Size cannot be less than 0")
    }

    ptr := make([]byte, size)
    if ptr == nil {
        panic("Memory allocation failed")
    }

    return ptr
}


In Go, `make` is used to create and initialize a slice, map, or channel only. Because Go manages memory automatically, rather than using a malloc equivalent, it’s actually usually more appropriate to use the "make" function. 

`size_t` in the `C` program has been converted to `int` in the `C` because there is no equivalent to `size_t` in `Go`. 

Therefore, we have replaced the `BTC_malloc` method with the `BtcMalloc` method, which implemented in `Go` programming language. It creates and initialized the slice.