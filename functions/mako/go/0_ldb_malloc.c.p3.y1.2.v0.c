go
import (
	"os"
	"unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
	ptr := C.malloc(C.size_t(size))

	if ptr == nil {
		os.Exit(1)
	}

	return ptr
}

Please note that using malloc in Go is not idiomatic. This is not the usual type of function you'd write in Go as it leverages `C.malloc` to allocate memory, and Go has built-in language features for all memory allocation. Moreover, using `C.malloc` requires CGO that leads to inefficiencies and potential compatibility issues. In general, best practices in Go suggest to use Go's own built-in garbage collected memory management with make, new, and so forth. It also should be noted that `unsafe.Pointer` should be used with caution.