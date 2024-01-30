go
type GetBitContext struct {
	index               uint
	buffer              []uint8
	size_in_bits_plus8  uint
}

func get_bits1(s *GetBitContext) uint8 {
	index := s.index
	result := s.buffer[index >> 3]
	
	result >>= index & 7
	result  &= 1

	if s.index < s.size_in_bits_plus8 {
		index++
	}
	
	s.index = index

	return result
}

Assumptions:

1) There is no support for pre-processor directive in Go lilee `BITSTREAM_READER_LE` and `UNCHECKED_BITSTREAM_READER` and the processing they are affecting, so those sections have been omitted.
 
2) "uint8_t result" in equivalent datatype in Go is "uint8 result".

Please tailor this to fit the context in which it will be used.