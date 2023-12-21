Go
type GetBitContext struct {
    index               uint
    size_in_bits_plus8  uint
    buffer              []byte
}

func get_bits1(s *GetBitContext) uint8 {
    index := s.index
    result := s.buffer[index >> uint(3)]

    result >>= index & uint(7)
    result &= uint8(1)

    if s.index < s.size_in_bits_plus8 {
        index++
    }

    s.index = index

    return result
}
