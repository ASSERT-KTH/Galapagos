go
import (
    "os"
    "unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
    ptr, err := os.Getwd(size)
    if err != nil {
        panic(err)
    }
    return ptr
}
