Below is the semantically equivalent version of the given C code. Given that there is not enough context to recreate the entire function but a general implementation seems like this:

go
type GetBitContext struct {
	Index int
	Buffer []uint8
	SizeInBitsPlus8 int
}

func GetBits1(s *GetBitContext) uint8 {
	index := s.Index
	result := s.Buffer[index >> 3]
	if BITSTREAM_READER_LE {
		result >>= index & 7
		result  &= 1
	} else {
		result <<= index &7
		result >>= 8 - 1
	}
	if !UNCHECKED_BITSTREAM_READER {
		if s.Index < s.SizeInBitsPlus8 {
			index++;
		}
	}
	s.Index = index

	return result
}


Please note,
- The keyword `static inline` in C function is just used to guide the compiler's optimizer. No equivalent is used in the Go version.
- Definitions of `BITSTREAM_READER_LE` and `UNCHECKED_BITSTREAM_READER` or equivalent data handling is not provided in the C snippet. Here, these serve as placeholders for constants or conditions which would be defined elsewhere in your code.
- The bit-wise operations, implemented in this Go version, adhere completely to provided C code. Beware! It depends whether they make sense to Go language representation.
- Go doesn't support unsigned int arithmetic natively, but using int with additional boundary conditions can well serve the purpose.