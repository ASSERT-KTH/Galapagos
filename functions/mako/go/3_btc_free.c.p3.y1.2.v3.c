func btcFree(ptr *interface{}) {
    if ptr == nil {
        panic("Null pointer error...")
    }

    ptr = nil
}