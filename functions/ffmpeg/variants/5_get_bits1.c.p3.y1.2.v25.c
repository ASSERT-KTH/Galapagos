Here is the Go equivalent of the provided C code:
go
type GetBitContext struct {
	index               uint32
	buffer              []byte
	size_in_bits_plus8  uint32
}

const (
	BITSTREAM_READER_LE         = true  
	UNCHECKED_BITSTREAM_READER  = false 
)

func get_bits1(s *GetBitContext) uint8 {
	index := s.index
	result := s.buffer[index>>3]
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
	}
	s.index = index

	return result
}

This code assumes a little-endian bitstream and unchecked bitstream reader available from the `unsafe` package. As Go doesn't have preprocessing directives like `#define` in C, we've defined them as constants which change their values would allow the change of the original behaviour. Please handle this function with care regard to endianness and unchecked readings, and adjust these constants to suit your application.