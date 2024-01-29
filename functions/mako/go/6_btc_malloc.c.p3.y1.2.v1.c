func btcMalloc(size uint) []byte {
    ptr := make([]byte, size)

    if ptr == nil {
        log.Fatalln("Allocation failed")
    }

    return ptr
}