Here is a semantically equivalent function in the Go programming language, relying on the `Zero` function from the `byte` package. 

go
import "bytes"

func sodium_memzero(pnt []byte, len int) {
	bytes.Zero(pnt[:len])
}


This implementation exhibits the same behaviour as the original C function - i.e., it assigns zeroes to a block of memory of the specified length. However, there are fundamental differences between how C and Go work at low level especially when it comes to manipulating the memory. This makes writing a native Go version of secure memory cleanup functionality a more complex task because writing directly to memory isn't common in Go - instead, you would usually use libraries specifically designed for safe memory management. Another crucial difference is that in C its necessary to manage memory due to possibilities of security vulnerabilities, however Go garbage collector is much more predictable making such low level manipulations often unnecessary. This understanding should be taken to account when migrating other low level C code to Go.