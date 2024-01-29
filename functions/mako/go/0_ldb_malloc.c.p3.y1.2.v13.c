go
import (
    "os"
    "unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
    ptr, err := syscall.Mmap(-1, 0, int(size), syscall.PROT_READ|syscall.PROT_WRITE, syscall.MAP_ANON|syscall.MAP_PRIVATE)
    
    if err != nil {
        os.Exit(1)
    }
    
    return unsafe.Pointer(&ptr[0])
}
