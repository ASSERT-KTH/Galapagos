go
type Jpeg2000DecoderContext struct {
	bit_index int
	g  *byteStream
}

type byteStream struct {
	data []byte
}

func (bs *byteStream) get_byte() uint {
	byte := bs.data[0]
	bs.data = bs.data[1:]
	return uint(byte)
}

func (bs *byteStream) peek_byte() uint {
	return uint(bs.data[0])
}

func get_bits(s *Jpeg2000DecoderContext, n int) int {
	res := 0

	for n-- >= 0 {
		res <<= 1
		if s.bit_index == 0 {
			s.bit_index = 7
			if s.g.get_byte() != 0xFF {
				s.bit_index = 8
			}
		}
		s.bit_index--
		res |= int(s.g.peek_byte() >> s.bit_index) & 1
	}
	return res
}

Note: As Go is a garbage collected language unlike C, deserialization shouldn't be mistakenly understood. This means instead of pointer manipulations the remaining bytes are removed by using native go slicer on "get_byte " and redundant check if the byteStream is empty has been omitted than C version's EOF equivalence of 'bytestream2_get_byte' check.