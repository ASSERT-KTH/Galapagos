import (
    "unsafe"
)

func sodiumMalloc(size uintptr) unsafe.Pointer {
    ptr := C.malloc(C.size_t(size))
    if ptr == nil {
        return nil
    }
    C.memset(ptr, int(GARBAGE_VALUE), C.size_t(size))
    return ptr
}