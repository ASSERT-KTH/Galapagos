func ldbMalloc(size uintptr) unsafe.Pointer {
    ptr := C.malloc(C.size_t(size))

    if ptr == nil {
        panic("Failed to allocate memory")
    }

    return ptr
}