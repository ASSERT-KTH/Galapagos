go
import (
    "os"
    "unsafe"
)

func btcMalloc(size uintptr) unsafe.Pointer {
    ptr, err := os.NewHandle(size)
    if err != nil {
        panic(err)
    }
     
    return ptr
}
