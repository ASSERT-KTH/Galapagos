Go
import (
    "os"
    "unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
    ptr, err := syscall.Mmap(-1, 0, int(size), syscall.PROT_NONE, syscall.MAP_ANON|syscall.MAP_PRIVATE)

    if err != nil {
        os.Exit(1)
    }

    return unsafe.Pointer(&ptr[0])
}
