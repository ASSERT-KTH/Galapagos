go
import (
	"log"
	"unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
	ptr, err := C.malloc(C.size_t(size))
	if err != nil {
		log.Fatal(err)
	}

	return ptr
}

This relationship is loosely equivalent. In Go, for system-level resource management, different approaches are practised like handling error directly through error values.

Firstly, remember that working directly with pointers in Go is not idiomatic (unlike C), it is recommended to leverage the Go garbage collector rather than manage memory directly. Another thing is Go has "panic" function but it doesn't have a direct equivalent for "abort". "log.Fatal" is considered an equivalent and normally used which logs the error message and calls os.Exit(1). Finally, Go does not include a direct analog to C's malloc function in its standard library, for safety and simplicity considerations.

If you seriously intend to call Unix-like system routines, consider using cgo that allows Go programs to call C code, but note that this usually significantly complicates the build process.
