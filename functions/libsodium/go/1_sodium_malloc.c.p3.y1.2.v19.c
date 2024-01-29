func sodiumMalloc(size uint) []byte {
    ptr := make([]byte, size)
    if ptr == nil {
        return nil
    }
    for i, _ := range ptr {
        ptr[i] = GARBAGE_VALUE
    }
    return ptr
}