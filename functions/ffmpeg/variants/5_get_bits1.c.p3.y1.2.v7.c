Here is Go equivalent for the above C program.

go
type GetBitContext struct {
	Index              uint
	Buffer             []uint8
	SizeInBitsPlusEight uint
}

func getBits1(s *GetBitContext) uint {
	index := s.Index
	result := s.Buffer[index>>3]

	result >>= index & 7
	result &= 1

	if s.Index < s.SizeInBitsPlusEight {
		index++
	}
	s.Index = index

	return uint(result)
}


Just to clarify, Go does not directly support pre-processor directives like `#ifdef`, `#else`, `#endif`, this is why the code now always runs according to the bitstream's endianness being little-endian (`BITSTREAM_READER_LE`) and `UNCHECKED_BITSTREAM_READER` not being defined.

Go does not support the usage of macros and conditional compilation the same was C does due to its clear benefit such as simplified debugging and quicker compilation speed.
To mirror the exact behaviour in C's preprocessor, the appropriate implementation approach will depend on better knowledge of the actual requirements which was not part of the original provided details.