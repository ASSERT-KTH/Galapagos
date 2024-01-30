type GetBitContext struct {
    Index             uint
    SizeInBitsPlus8   uint
    Buffer            []uint8
}

func getBits1(s *GetBitContext) uint8 {
    index := s.Index
    result := s.Buffer[index >> 3]

	const BITSTREAM_READER_LE = true
	if BITSTREAM_READER_LE {
		result >>= index & 7
		result &= 1
	} else {
		result <<= index & 7
		result >>= 8 - 1
	}

	const UNCHECKED_BITSTREAM_READER = false
	if !UNCHECKED_BITSTREAM_READER {
		if s.Index < s.SizeInBitsPlus8 {
			index++
		}
	}

	s.Index = index

    return result
}