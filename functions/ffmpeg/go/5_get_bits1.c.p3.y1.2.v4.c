go
type GetBitContext struct {
    index uint
    buffer []byte
    size_in_bits_plus8 uint
}

func get_bits1(s *GetBitContext) uint8 {
    index := s.index
    result := s.buffer[index >> 3]
    
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

Note that in Go constants are declared separately at package level and moreover this is a compiled language like C . So I used if conditions versus Pre-processor macros & Constants in C i.e. "#ifdef", "#endif", "#if" converted to correspondingly equivalent "if" statements/constants in Go.