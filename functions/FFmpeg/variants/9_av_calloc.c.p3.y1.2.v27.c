The function you provided uses custom functions (`size_mult` and `av_mallocz`). If these functions implemented standard C memory manipulation, their equivalents in Go would be a multiplication operation (for `size_mult`) and Go's `make` function (to simulate `av_mallocz` functionality).

Unfortunately, the Go programming language does not support the concept of void pointers, unlike C. Hence, the function cannot be directly converted while maintaining the original function's signature and being 'semantically equivalent'. 

However, in most scenarios of Go programming, memory allocation involves specific types rather than working with void pointers or size values. Without context of how this function is used in the C program we can only offer a Go alternative that uses an explicit data type:

go
func AllocateBytes(count int) []byte {
    return make([]byte, count)
}


This function in Go does similar memory allocation like your C function: taking in a value to determine the size of the memory to be allocated, and returning the pointer/reference to that memory block. But it is for bytes instead of void pointers. 

Should the C logic perform more complex operations such as multiply two values to compute size, these can be incorporated into the Go function straightforwardly:

go
func AllocateBytes(qty int, size int) []byte {
    return make([]byte, qty * size)
}


Hope this helps. Again, it should be noted it is theoretically impossible to complete a to-go translation incorporating the concept of void pointers in the input and output due to fundamental language architectural differences. Please provide more context for a better-suited result, should available.