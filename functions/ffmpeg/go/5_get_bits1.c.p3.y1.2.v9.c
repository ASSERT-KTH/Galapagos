go
type GetBitContext struct {
    Buffer            []byte
    Index             uint
    SizeInBitsPlus8   uint
}

func getBits1(s *GetBitContext) uint8 {
    index := s.Index
    result:= s.Buffer[index >> 3]

const BITSTREAM_READER_LE int = 1 
const UNCHECKED_BITSTREAM_READER int = 0
    if BITSTREAM_READER_LE == 1 {
        result >>= index & 7
        result  &= 1
    } else {
        result <<= index & 7
        result >>= 8 - 1
    }

    if UNCHECKED_BITSTREAM_READER != 1 {
        if(s.Index < s.SizeInBitsPlus8) {
            index++
        }
    } 

    s.Index = index

    return result
}
