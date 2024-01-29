Go
type GetBitContext struct {
    index                uint
    buffer               []uint8
    size_in_bits_plus8   uint
}

func getBits1(s *GetBitContext) uint {
    index := s.index
    result := s.buffer[index >> 3]
//simulate equivalence of BITSTREAM_READER_LE defines with simple bool check
if (true){
    result >>= index & 7
    result &= 1
    } else {
    result <<= index & 7
    result >>= 8 - 1
    }
//checking the prerequisites before increment 
    if s.index < s.size_in_bits_plus8 {
        index++
    }
    s.index = index

    return uint(result)
}
