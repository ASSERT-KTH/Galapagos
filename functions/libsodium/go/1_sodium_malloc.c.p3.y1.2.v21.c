Unfortunately, there are differences in memory management between C and Go that make a direct translation of this function impossible as including the equivalent of `malloc` and the `NULL` checks do not exist in Go. The mechanisms of control over low-level memory like `memset` is not present either as Go has Garbage Collection and General Memory Management that makes usage of these unnecessary or unable to do directly.

However, if it's only about returning a slice of bytes with specified length initialized in certain values (simulating _sodium_malloc(size)), you can write something similar as:

Go
func sodiumMalloc(size int) []byte {
	ptr := make([]byte, size)
	for i := range ptr {
		ptr[i] = GARBAGE_VALUE
	}
	return ptr
}


Where `GARBAGE_VALUE` is a predefined byte in your Go application. This creates a new byte slice with the specified size and initializes it with the garbage value, equivalent of `memset`.

Remember this does not take into account conditions on failed `malloc` as `make` function would panic instead of returning NULL. If an out-of-memory condition occurs, Go programs will panic.