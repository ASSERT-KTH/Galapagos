func btc_free(ptr *interface{}) {
    if ptr == nil {
		panic("ptr is null")
    } else {
		*ptr = nil
    }
}