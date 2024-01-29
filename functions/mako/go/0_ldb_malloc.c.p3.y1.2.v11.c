go
import (
    "os"
    "unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
    ptr, err := c.go_malloc(size)

    if err != nil {
        os.Exit(1)
    }

    return ptr
}
