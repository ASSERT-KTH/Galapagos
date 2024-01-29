go
import (
	"log"
	"unsafe"
)

func btcMalloc(size uintptr) unsafe.Pointer {
	ptr, err := C.malloc(C.size_t(size))
	if err != nil {
		log.Fatal("Allocating memory failed")
	}
	return ptr
}

NOTE: `C.malloc()` and `C.size_t` are methods and types provided by the "C" package in Go which only work in conjunction with cgo compiler directive. To use actual "safe" go implementation, memory management should be done automatically by the Go (which follows garbage collection principle), using inbuilt data structures and theirs constructors like `make` or defining new elements would be more appropriate.

This cgo-based Go function assumes the import of `"unsafe"` and `"log"` packages in Go as well as importing the cgo-based 'C' package. `C.malloc()` may return an error pointer `"cannot allocate memory"` if malloc failed pointed by `err` hence `err` will not be `nil`. We use FATAL level logging which concurrently calls to `os.Exit(1)`. Therefore, it replicates original C function behavior.
go
buf := make([]byte, size)
return unsafe.Pointer(&buf[0])

This is a better approximation of the original C function based purely on standard Go and the semantics of Go’s garbage collector. Here, `buf` is a slice with size provided similar to C `malloc`. `unsafe.Pointer(&buf[0])` will return the pointer to the first byte of this slice to be able to mock original function, lifecycle of this memory will be organized by garbage collector instead of developer's explicit `free`. Wrapping it with `unsafe.Pointer` does give you an opaque pointer you can pass around. Be aware! You are placing more responsibilties on the garbage collector and it takes the role of the code’s responsibility in managing the lifecycle of the malloc()'d hunk of memory. Notably, in Go nothing akin to the ABEND produced by `abort()` is required as the it will throw 'index out of range' panic automatically upon issue.