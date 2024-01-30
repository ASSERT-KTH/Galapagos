func btcFree(ptr unsafe.Pointer) {
	if ptr == nil {
		panic("null pointer passed to free")
	}

	C.free(ptr)
}