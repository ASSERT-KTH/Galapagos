func btcFree(ptr *interface{}) {
	if ptr == nil {
		panic("Abort: Nil Pointer.")
		return
	}

	*ptr = nil // In Go, freeing memory is handled by the garbage collector
}