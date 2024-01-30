It is not possible in Go to implement a completely semantically equivalent function to the one in C as given, due to the dynamic type safety and garbage collection in Go. However, the underlying spirit is that you want to allocate a block of memory and prefill it with a value. Here is the closest reusable Go alternative:

go
import "bytes"

func sodiumMalloc(size int) []byte {
    return bytes.Repeat([]byte{GARBAGE_VALUE}, size)
}


Here, `sendCmd` receives a byte slice which can be used just like a void array in the C language. `bytes.Repeat` creates a new slice with a specified length of filled values.

The Go standard library does not provide way to intentionally leak memory, as Go has a garbage collector in place which continuously de-allocate any inaccessible piece of heap memory.

Also, note that no error handling is needed, because, unlike in C where `malloc` might fail and return `NULL`, Go's runtime increases the process's memory automatically.

The cast to `(int)` for `GARBAGE_VALUE` was removed because byte array index needs a byte, you will have to make sure GARBAGE_VALUE is within the appropriate range of byte (`0-255`). Also, to be able to specify GARBAGE_VALUE you must define it genuinely or directly inline.