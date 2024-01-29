func btcFree(ptr unsafe.Pointer) {
    if ptr == nil {
        panic("nil pointer provided to free operations")
    }

    C.free(ptr)
}