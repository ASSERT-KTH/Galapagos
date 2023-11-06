In Go language, there's not strict equivalent to C's calloc. The use case is often replaced with `make` statement or occasionally new/make usage combination. Outputting similar behavior that acts as calloc could be:

go
func av_calloc(nmemb int, size int) []byte {
    product := nmemb * size // if overflow, it appears Go program will crash, which is recent behavior
    return make([]byte, product) // this translates to av_malloc and clear mem to 0
}


The `make` built-in function is used to allocate and initialize a slice, map, or channel (but not a simple type like int). It makes zero-valued array of nmemb*size, which corresponds to av_mallocz in C where allocated memory block is set to 0.
    
Please note that C language is more low level than Go language. In Go, his higher level operations automatically initializes all allocated memory to zero and prevents manual calculation and conversion of sizes.