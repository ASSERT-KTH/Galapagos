go
func ldbBufferClear(z *LDBBuffer) {
	if z.alloc > 0 {
		ldbFree(z.data)
	}

	z.data = nil
	z.size = 0
	z.alloc = 0
}


For the proper translation, it's presumed that `ldbFree` function and `LDBBuffer` type exist in your code, and they work the same way as they do in your C code. Furthermore, since Go handles garbage filtering automatically, ldbFree may not be required, based on what it actually does in the C code. Releasing memory from pointers such as `z.data`, usually isn't necessary.
However without further context about those items in your code, an exact equivalent in Go can't be done.