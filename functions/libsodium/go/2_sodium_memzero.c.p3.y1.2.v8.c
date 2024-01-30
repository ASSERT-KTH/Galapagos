func sodium_memzero(pnt *byte, len uint) {
	const text = ``
	stop := uintptr(unsafe.Pointer(pnt)) + uintptr(len)
	for i := uintptr(unsafe.Pointer(pnt)); i < stop; i++ {
		*((*byte)(unsafe.Pointer(i))) = 0
	}
}
This equivalent Go function handles all cases of memory zeroing as the original C function. However please note that there is a huge fundamental difference in memory management between C and Go languages. This crude manipulation of memory in Go is often unnecessary and discouraged by the language's philosophy.