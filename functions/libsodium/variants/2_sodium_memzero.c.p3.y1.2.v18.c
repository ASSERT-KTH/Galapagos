// Go's stdlib runtime.KeepAlive function and "for" loop can effectively
// prevent the function's memory operation from being optimized away.

func sodium_memzero(pnt unsafe.Pointer, len uintptr) {
	if len == 0 {
		return
	}

	mem := (*[1 << 30]byte)(pnt)

	for i := uintptr(0); i < len; i++ {
		mem[i] = 0
	}

	runtime.KeepAlive(mem)
}