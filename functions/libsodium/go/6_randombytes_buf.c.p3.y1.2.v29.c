Assuming that `randombytes_init_if_needed` and `implementation.buf` are equivalent functions available in the Go environment translated appropriately, the translated function would look like this:

go
func randombytes_buf(buf []byte, size int) {
    randombytes_init_if_needed()
    if size > 0 {
        implementation.buf(buf, size)
    }
}


Side note: One key observation is the typing difference of `size` from C's `size_t` (usually unsigned int) to Go's `int` - Go generally encourages using `int` for size-related quantities. This might need to be adapted according to your specific situation (that is, if negative indices are a possibility, another approach might be needed). 

Moreover, buffer (`buf`) is manipulated as a slice of bytes (`[]byte`). Slices in Go can be utilized to fit the variability and dynamic of C style `void* buf`. This assumes that the bytecode generated or the underlying function in implementation.buf manipulates/animate over the `void* buf` the same way as Go does over slices.