func btcMalloc(size uint) []byte {
    ptr := make([]byte, size)

    if ptr == nil {
        panic("Memory allocation failed")
    }

    return ptr
}