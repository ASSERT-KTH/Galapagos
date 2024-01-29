In Go, we have the native `make` function that creates slices, maps, and channels only. For allocating Zeroed memory use the `Calloc` method of the `C` package. If the resulting data type is going to be a slice, you can use `make` to always receive a zeroed slice. If it's not a slice, better stick to C's method `Calloc`.

However, in the Go programming language, it isn't possible to precisely match the semantics of the C function `av_calloc`. This is particularly due to Go's lack of pointers arithmetic and that memory allocation always returns zero initialized memory.

The only possible close equivalence to it might look like this using Go's native capabilities:

go
import "C"

func AvCalloc(nmemb C.size_t, size C.size_t) *C.void {
    result := (nmemb * size)
    return C.calloc(1, result)
}

Note: A direct translation to zeroed memory allocation (C's "calloc") is not usually necessary in Go, there might be high-level constructs that serve the same purpose in a more 'Go-like' way. Also, remember this requires CGO (so cgo must be enabled) and is not the approved understanding for writing code in Go. Like said before, Memory allocation in Go automatically zeroes out the memory. Depending on different situations, `make`, `new` is normally used.
Please refer to golang docs.