func sodiumMemzero(pnt unsafe.Pointer, len uintptr) {
	b := (*[1 << 30]byte)(pnt)[:len:len]
	for i := range b {
		b[i] = 0
	}
}