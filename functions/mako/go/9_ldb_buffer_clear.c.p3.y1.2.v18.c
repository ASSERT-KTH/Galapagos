Assuming a defined type `LDBBuffer` in Go that is equivalent to `ldb_buffer_t` in C, as Go doesn't have explicit pointers to make changes to struct objects, as objects are essentially passed by reference.

Go
type LDBBuffer struct {
	Alloc int
	Size  int
	Data  []byte
}

func LDBBufferClear(z *LDBBuffer) {
	if z.Alloc > 0 {
		z.Data = nil
	}

	z.Data = nil
	z.Size = 0
	z.Alloc = 0
}
