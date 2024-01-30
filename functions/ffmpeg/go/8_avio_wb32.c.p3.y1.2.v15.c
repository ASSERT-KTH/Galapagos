There isn't a direct equivalent in Go for the AVIOContext struct and the corresponding avio_w8 function seen in the C implementation that you provided. Therefore I will give a general concept of how one may go about writing such a function in Go.

We may create a Writer type, that mirrors the concept of AVIOContext in C and supplies the avio_w8(). It all depends on your actual Go implementation. This example uses a simple byte slice []byte("string"). Your actual implementation may differ.

Here is such a conceptual translation of the function from C to Go:

Go
type AVIOContext struct {
	Buffer *bytes.Buffer
}

func (s *AVIOContext) avio_w8(val byte) {
	_, _ = s.Buffer.Write([]byte{val})
}

func (s *AVIOContext) avio_wb32(val uint32) {
	s.avio_w8(byte(val >> 24))
	s.avio_w8(byte(val >> 16))
	s.avio_w8(byte(val >> 8))
	s.avio_w8(byte(val))
}


Please replace this with whatever AVIOContext or avio_w8() equivalent you may have in your actual Go implementation. This is just meant to show how the byte write operations from C could be done in Go given such a context.