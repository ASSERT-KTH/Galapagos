Since Go doesn't have the concept of raw memory allocation or concept like GARBAGE_VALUE, given as in the C code, the equivalent version of this function in Go might look like this:

go
import "bytes"

func sodiumMalloc(size int) []byte {
	ptr := make([]byte, size)
	if ptr == nil {
		return nil
	}

	ptr = bytes.Repeat([]byte{0}, size)

	return ptr
} 


This function creates a byte slice that equivalent to the memory allocation in `C`. Also, zero(initialized memory in Go) is used instead of `GARBAGE_VALUE`. The Go run time ensures that make doesn't return `nil` on successful allocation, thus there is no direct equivalent check, in case you need the explicit check you can use panic/recover combination. It should be noted though in Go, unlike in `C` working with raw memory isn't a common use, and void pointers don't exist, you will have to deal with strongly typed data or byte buffers mostly. We could return a byte buffer as the modern version of raw memory but filling incomplete memory isn't represented directly nor allocated but value is generally initialized immediately.