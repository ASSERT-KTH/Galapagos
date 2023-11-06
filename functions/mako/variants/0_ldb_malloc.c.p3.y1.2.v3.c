go
import (
    "os"
    "unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
    ptr, err := os.Mmap(-1, size, os.O_RDWR, os.MAP_ANON | os.MAP_PRIVATE, 0)

    if err != nil {
        panic(err)
    }

    return unsafe.Pointer(&ptr[0])
}
