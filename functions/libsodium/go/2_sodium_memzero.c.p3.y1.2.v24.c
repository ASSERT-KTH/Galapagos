The _sodium_dummy_symbol_to_prevent_memzero_lto and sodium_misuse used in the original function seem to be project-specific dependencies and are not standard C library functions. For this reason their implementation in Golang has to be customized depending on their behavior in the relative project.

However, if we ignore these calls for this conversion, we can implement the equivalent logic in Go like this:

go
import (
	"unsafe"
	"runtime"
)

func Sodium_memzero(ptr unsafe.Pointer, len uintptr) {
	b := (*[1 << 40]byte)(ptr)[0:len]
	for i := range b {
		b[i] = 0
	}
	// Make sure the compiler does not optimize out the zeroing operation.
	runtime.KeepAlive(b)
}


Note that `unsafe.Pointers` should be handled with great care because making unsafe modifications can lead to unpredictable outcomes and the `runtime.KeepAlive` ensures the operation is performed before garbage collection.

Also, there are some different preprocessor conditions depending on the presence of several libraries (the real use depends in the operational environment where the code will run). When writing the code in Go, usually we assume to live in a standardized and universal environment (the Go runtime). Most of these conditions can safely be ignored in Go as the standard library will only implement optimized routines where possible.

And to be more effective, operations like these are quite often done in a more per-formed way where the Go's garbage collector get involved. When using efficient data types object allocations than attempting to clear a segment of memory, Go's GC ensures within the lifetime of an object usage and prevents object living after their used lifetime.