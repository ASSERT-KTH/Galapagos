go
type GetBitContext struct {
	index               uint32
	buffer              []byte
	sizeInBitsPlus8     uint32
	bitstreamReaderLE   bool
	uncheckedBitstreamReader bool
}

func getBits1(s *GetBitContext) uint8 {
	index := s.index
	result := s.buffer[index >> 3]
	if s.bitstreamReaderLE {
		result >>= index & 7
		result &= 1
	} else {
		result <<= index & 7
		result >>= 8 - 1
	}
	if !s.uncheckedBitstreamReader {
		if s.index < s.sizeInBitsPlus8 {
			index++
		}
	}
	s.index = index

	return uint(result)
}

This Go version preserves the original function's signature and narrative, but use boolean indicators for flags. The GetBitContext struct has been updated to include these indicators.