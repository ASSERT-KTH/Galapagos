func ldbBufferClear(z *ldbBuffer_t) {
	if z.alloc > 0 {
		ldbFree(z.data)
	}

	z.data = nil
	z.size = 0
	z.alloc = 0
}