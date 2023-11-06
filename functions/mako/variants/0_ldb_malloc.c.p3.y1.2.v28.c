go
import (
    "os"
    "unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
    ptr := C.malloc(C.size_t(size))

    if ptr == nil {
        os.Exit(1) // Equivalent of C's abort()
    }

    return ptr
}


C library should be imported for using malloc function using `import "C"` at the start of the program and should be built using `Cgo`. If a pure Go solution is preferred, a package like `"runtime"` can deliver similar functionality but nevertheless, Go already manages memory consumption using garbage collection and doesn't have direct equivalence for C's `malloc()`.