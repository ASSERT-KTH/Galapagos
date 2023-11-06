go
import (
    "os"
    "unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
    ptr, err := os.New("uint8", new(size))

    if err != nil {
        panic(err)
    }

    return unsafe.Pointer(ptr)
}
