go
type Jpeg2000DecoderContext struct {
	g         Bytestream2
	bit_index int
}

func (s *Jpeg2000DecoderContext) get_bits(n int) int {
	res := 0
	for n--; n >= 0; n-- {
		res <<= 1
		if s.bit_index == 0 {
			if s.g.get_byte() != 0xFF {
				s.bit_index = 8 // Num bits in a byte in Go, note that theres 1 based indexing
			} else {
				s.bit_index = 7 // 7 taken straight away from C code 
			}
		} 
		s.bit_index--
		res |= int((s.g.peek_byte() >> s.bit_index) & 1)
	}
	return res
}
