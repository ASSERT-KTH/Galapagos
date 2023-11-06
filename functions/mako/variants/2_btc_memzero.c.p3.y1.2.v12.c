func btc_memzero(ptr unsafe.Pointer, len uintptr) {
	if len > 0 {
		C.memset(ptr, 0, len)
	}
}