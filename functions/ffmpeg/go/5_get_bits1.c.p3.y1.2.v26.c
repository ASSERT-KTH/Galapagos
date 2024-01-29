type GetBitContext struct {
    Index             int
    Buffer            []byte
    SizeInBitsPlus8   int
}

func getBits1(s *GetBitContext) uint8 {
    index := s.Index
    result := s.Buffer[index >> 3]
    
    result >>= index & 7
    result &= 1

    if result != 0 {
        if s.Index < s.SizeInBitsPlus8 {
            index++
        }
    } else {
        result <<= index & 7
        result >>= 8 - 1
        if s.Index < s.SizeInBitsPlus8 {
            index++
        }
    }

    s.Index = index
    return result
}