go
type ldbBufferT struct {
    data []byte
	size int
	alloc int
}

func ldbBufferClear(z *ldbBufferT) {
	if z.alloc > 0 {
	    z.data = nil
	}

	z.size = 0
	z.alloc = 0
}


Please note that the ldb_free in the C code, was not replicated in its Go segment. This is important because memory management in Go is quite different from C. Go utilizes a garbage collector which makes manual memory deallocation unnecessary. 

That's why it's difficult to make a perfect one-to-one conversion of not just this, but many code snippets between Go and C. Memory management model and language structures are somewhat distinct.