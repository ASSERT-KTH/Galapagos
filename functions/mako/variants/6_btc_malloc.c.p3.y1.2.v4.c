func btcMalloc(size uint32) []byte {
    buffer := make([]byte, size)

    if buffer == nil {
        panic("Failed to allocate memory")
    }

    return buffer
}