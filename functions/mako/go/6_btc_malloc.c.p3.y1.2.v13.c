go
import (
    "os"
    "unsafe"
)
func BtcMalloc(size uintptr) unsafe.Pointer {
    ptr := C.malloc(C.size_t(size))
    if ptr == nil {
        os.Exit(1)
    }
    return ptr
}
