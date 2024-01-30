type GetBitContext struct {
	Index                int
	SizeInBitsPlus8      int
	Buffer               []byte
}

func getBits1(s *GetBitContext) (result uint8) {
	index := s.Index
	result = s.Buffer[index >> 3]
#ifdef BITSTREAM_READER_LE
	result = result >> (index & 7)
	result = result & 1
#else
	result = result << (index & 7)
	result = result >> (8 - 1)
#endif
#if !UNCHECKED_BITSTREAM_READER
	if s.Index < s.SizeInBitsPlus8 {
		index++
	}
#endif
	s.Index = index
	return result
} 

Please note, Go does not support actual Macros like in C/C++. Also this logic is not properly specified, so things like throw error or default values return for `BITSTREAM_READER_LE` and `UNCHECKED_BITSTREAM_READER` is vaguely defined.
In consideration of the stated facts, the provided functionality of the C code is put into go code to the possible extent.
It is advised to interactively take needed action is undefined logic based on different value of `BITSTREAM_READER_LE` and `UNCHECKED_BITSTREAM_READER`.