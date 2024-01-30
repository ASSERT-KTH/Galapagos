In Go, we do not directly handle memory allocation like in C or C++. The Go's garbage collector will be responsible for memory management. Hence translating C's calloc to Go doesn't make much sense in the exact way, but a semantically equivalent version, meeting your stated requirement of maintaining the same function signature would be as follows.

Please note: There's no builtin multiplication methods in Go that return any error like C's multiplication. In panic case, Go program simply halts so I don't return any value like NULL in C

go
package main

import "fmt"

func av_calloc(nmemb, size int64) []byte {
    if nmemb < 0 || size < 0 {
        return nil
    }
    return make([]byte, nmemb * size)
}


Here, I am using Go's slice. Slices in Go have variable sizes and can be resized unlike Arrays in C. They function similarly to dynamic arrays and are more feature rich compared to arrays.