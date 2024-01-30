Go
import (
    "os"
    "unsafe"
)

func LdbMalloc(size uintptr) unsafe.Pointer {
    ptr, err := os.Mmap(nil, int(size), os.PROT_READ|os.PROT_WRITE, os.MAP_ANON|os.MAP_PRIVATE, -1, 0)
    if err != nil {
        os.Exit(1)
    }
    return unsafe.Pointer(&ptr[0])
}
