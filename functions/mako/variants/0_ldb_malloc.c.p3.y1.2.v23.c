go
import (
    "os"
    "unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
    ptr, err := os.Mmap(-1, int(size), os.O_RDONLY, os.MAP_PRIVATE, 0)
    if err != nil {
        panic(err)
    }
    return unsafe.Pointer(&ptr[0])
}

Note:
Go does not have "malloc" it uses a garbage collector to manage memory.
So the above Go function maps a region of the process's virtual memory as Linux does, and give out pointers similarly like malloc does in C. The “os” package does not permit control of all mmap flags.