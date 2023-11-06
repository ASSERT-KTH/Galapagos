go
import (
    "os"
    "unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
    ptr, err := C.malloc(C.size_t(size))

    if err != nil {
        os.Exit(1)
    }

    return ptr
}

Notes:
1. In contrast to C, errors in Go are often treated as regular values, using `os.Exit(1)` here even though in Go it's better to return error in most cases to allow the caller to decide what to do in case of failure.
2. We don't use built-in Go ways to allocate memory here because Go uses garbage collector to manage memory while C does not.
3. `C.malloc()` is a pseudo-call to `C` (The C package). You would have to leverage the features of CGO (pronounced "C-Go"), a Go package which allows you to integrate C libraries directly into your Go program.
This is needed because a Go program cannot accurately be written to follow the semantics of this C code, As Go has automatic memory management i.e., Garbage Collection and does not expose raw `malloc()` and `free()` function calls.