Please be aware that translating this function\'s behavior to Go isn't a perfect match due to the different approach that Go has regarding memory allocation and error handling. However, the closest equivalent you would have is probably along these lines go 

go
package main

import(
    "os"
)

func btc_malloc(size int) []byte {
    /*In Go, we make use of slices for dynamic allocation*/
    ptr := make([]byte, size)

    if ptr == nil {
        os.Exit(1)
    }

    return ptr
}
