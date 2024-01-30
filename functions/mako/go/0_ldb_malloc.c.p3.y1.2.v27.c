
import (
    "os"
    "unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
    ptr := C.malloc(size)

    if ptr == nil {
        os.Exit(1)
    }

    return ptr
}

Please note that this Go function will actually not serve the exact similar purpose, because Go uses `Garbage Collection` to manage program's memory usage and doesn't encourage the use of `python malloc` or Go's equivalent `C.malloc`, which is considered low level system call in Go lang and ideally should not be handled manually in your program, instead, should be left to `Go runtime` to take care of those. Please re-read the Go's Memory Management implications before using the given function.