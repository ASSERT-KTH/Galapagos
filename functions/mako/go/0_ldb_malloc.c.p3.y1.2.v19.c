Go
import (
    "os"
    "unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
    ptr, err := C.malloc(C.size_t(size))

    if err != nil {
        os.Exit(1)
    }

    return ptr
}

This Go code emulates the behavior of the provided C code snippet. it uses unsafe and os packages for memory allocation and handling failure respectively. It tries to allocate memory using C malloc, and if it couldn't be located, the application will be exited with exit code 1 which denotes an error.

Please note this code uses a deprecated CGo package as standard Go's philosophy discourages directly manipulating memory like in C. It attempts to protect programmers from usual mistakes related to manual memory management via garbage collection. Consider altering this code snippet according to more idiomatic Go practices if you run into problems.