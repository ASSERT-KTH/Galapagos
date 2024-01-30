The direct translation of the C code function into Go is a straightforward task but the resulting function might not be entirely idiomatic in Go. With this assumption, here is the direct translation:

go
func getBits(s *GetBitContext) uint8 {
    index := s.index
    result := s.buffer[index >> 3]
    
    const (
        BITSTREAM_READER_LE           = true  // Set to false based on your requirements
        UNCHECKED_BITSTREAM_READER    = false // Set to false based on your requirements
    
    if BITSTREAM_READER_LE {
        result >>= index & 7
        result &= 1
    } else {
        result <<= index & 7
        result >>= 8 - 1
    }
     
    if !UNCHECKED_BITSTREAM_READER {      
        if s.index < s.sizeInBitsPlus8 {
            index++
        }
    } else {                             
        index++
    }
    
    s.index = index
    
    return result
}

type GetBitContext struct {
    index           uint
    buffer          []uint8
    sizeInBitsPlus8 uint
}

A few remarks to remember:

- Structs in Go don't have fields of type unsigned int as in C. Instead, it has uint (uint8, uint16, uint32, uint64) along with int (int8, int16, int32, int64).

- Naming conventions in Go always favors camelCase variable naming, e.g., `sizeInBitsPlus8` whereas `size_in_bits_plus8` is a style that is used in C.

- Lastly, Ensure `BITSTREAM_READER_LE` and `UNCHECKED_BITSTREAM_READER` have the expected value reflecting C implementation. As constants are picked up at compile-time rather than run-time, if you want these to be configurable, consider changing them to var variables or providing them as arguments in the `GetBits` function.