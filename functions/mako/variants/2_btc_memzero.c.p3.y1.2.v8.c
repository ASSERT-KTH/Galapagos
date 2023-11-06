func btcMemzero(ptr *byte, len uintptr) {
	if len > 0 {
		for index := range make([]byte, len) {
			ptrVal := uintptr(unsafe.Pointer(ptr)) + uintptr(index)
			*(*byte)(unsafe.Pointer(ptrVal)) = 0
		}
	}
}