type GetBitContext struct {
	index               uint32
	size_in_bits_plus8  uint32
	buffer              []byte
}

func get_bits1(s *GetBitContext) uint8 {
	index := s.index
	result := s.buffer[index>>3]
	result >>= index & 7
	result &= 1
	if s.index < s.size_in_bits_plus8 {
		index++
	}
	s.index = index
	return uint8(result)
}