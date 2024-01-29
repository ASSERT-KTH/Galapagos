func btcFree(ptr *interface{}) {
    if ptr == nil {
        panic("Nil pointer passed to free")
    }

    ptr = nil 
}