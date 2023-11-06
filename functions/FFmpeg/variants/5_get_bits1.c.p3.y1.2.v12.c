go
type GetBitContext struct {
	index               uint
	size_in_bits_plus8  uint
	buffer              []byte
}

func getBits1(s *GetBitContext) uint8 {
	index := s.index
	result := s.buffer[index >> 3]
	result >>= index & 7
	result &= 1

    if s.index < s.size_in_bits_plus8 {
       index++;
    }

	s.index = index
	return uint8(result)
}

NOTE: Assuming that `BITSTREAM_READER_LE` and `UNCHECKED_BITSTREAM_READER` are compilation flags in the C code, I have removed the corresponding sections from the Go version because Go does not support preprocessor directives. Definition or choice of behaviour for those conditions must be created programmatically.