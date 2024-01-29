func ldbBufferClear(z *LdbBuffer) {
	if z.alloc > 0 {	
		z.data = nil
	}
	z.size = 0
	z.alloc = 0
}