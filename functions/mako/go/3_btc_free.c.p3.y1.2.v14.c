func btcFree(ptr *interface{}) {
    if ptr == nil {
        panic("null pointer")
    }

    *ptr = nil
}