go
import (
    "os"
    "unsafe"
)

func LdbMalloc(size uintptr) unsafe.Pointer {
    ptr, err := C.malloc(C.size_t(size))
    if err != nil {
        os.Exit(1)
    }

    return unsafe.Pointer(ptr)
}


This Go equivalent uses the `C.malloc` function from C's libraries to directly port over the code implementation from the original ldb_malloc function from C to Go. The imported `unsafe` package allows Go to truly replicate the behavior of malloc in C, as variables of type `uintptr` and `unsafe.Pointer` are used for the malloc call, allowing Go to manage memory in a more manual, low-level fashion like what is required in malloc'd pointers in C. If the malloc call does not succeed, Go will properly terminate the program by calling `os.Exit(1)`.