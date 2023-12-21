Here is the Go version of the function:

go
type GetBitContext struct {
	index               uint32
	buffer              []uint8
	size_in_bits_plus8  uint32
}

func get_bits1(s *GetBitContext)  uint8 {
	index := s.index
	result := s.buffer[index >> 3]
	const BITSTREAM_READER_LE = true // assuming as true
	const UNCHECKED_BITSTREAM_READER = false // assuming as false
	if BITSTREAM_READER_LE {
		result >>= index & 7
		result &= 1
	} else {
		result <<= index & 7
		result >>= 8 - 1
	}
	
	if !UNCHECKED_BITSTREAM_READER && s.index < s.size_in_bits_plus8 {
		index++
	} 
	s.index = index
	
	return result
}

The exact translation in Go depends on how the BITSTREAM_READER_LE and UNCHECKED_BITSTREAM_READER constants are defined in your C code. I assumed them as true and false respectively for this example. If they are not constants or their values can change, you would need to adapt this code accordingly. Moreover, I also assumed that the "size_in_bits_plus8" is the size of "buffer" in bits plus 8 based on its name. If this is not the case, you again need to adjust the code correspondingly.