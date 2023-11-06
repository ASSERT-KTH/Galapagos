func btc_free(ptr *interface{}) {
    if ptr == nil {
        panic("attempted to free nil pointer") 
    }

    ptr = nil
}