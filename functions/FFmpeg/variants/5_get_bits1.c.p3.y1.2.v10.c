go
type GetBitContext struct {
	index               uint
	size_in_bits_plus8  uint
	buffer              []byte
}

const (
	BITSTREAM_READER_LE        = false   // You can set this according to your requirement
	UNCHECKED_BITSTREAM_READER = false   // You can set this according to your requirement
)

func getBits1(s *GetBitContext) uint {
	index := s.index
	result := s.buffer[index >> 3]

	if BITSTREAM_READER_LE {
		result >>= index & 7
		result &= 1
	} else {
		result <<= index & 7
		result >>= 8 - 1
	}

	if !UNCHECKED_BITSTREAM_READER {
		if s.index < s.size_in_bits_plus8 {
			index++
		}
	} else {
		index++
	}

	s.index = index

	return uint(result)
}
