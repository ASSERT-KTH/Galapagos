As Go has built-in support for growing arrays/slices, it isn't typical to pre-allocate memory in a similar fashion like in this C code. However, here's an equivalent functionality in context of Go:

go
func avCalloc(nmemb, size int) []byte {
    result := nmemb * size

    return make([]byte, result)
}


Go behaves differently from C/C++ on out of memory error and it uses `panic` in such situations instead of returning `NULL` pointers, so this behavior isn't copied in this method from the method of C. The built-in function `make` is used to allocate a zeroed byte slice of `size` instead of behaving like the `av_mallocz` function in the C code. Assume that size and nmemb are of integer types as Go doesn't support `size_t` type. It's worth noting that Go performs garbage collection automatically and also it's safe from memory leaks unlike C/C++. Please keep this difference in mind while doing implementations around memory allocation in Go.