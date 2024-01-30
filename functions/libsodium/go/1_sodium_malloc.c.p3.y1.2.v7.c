func sodiumMalloc(size int) []byte {

    ptr := make([]byte, size)
    if ptr == nil {
        return nil
    }
    for i:= range ptr {
        ptr[i] = 'GARBAGE_VALUE'
    }
    return ptr
}