Here is the equivalent function you asked for in Go:

go
func getBits1(s *GetBitContext) uint8 {
    index := s.index
    result := s.buffer[index>>3]
    switch bitstreamReaderLE := true; bitstreamReaderLE {
    case true:
        result = result >> (index & 7)
        result = result & 1
    default:
        result = result << (index & 7)
        result = result >> (8-1)
    }

    if !uncheckedBitstreamReader {
        if s.index < s.sizeInBitsPlus8 {
            index++
        }
    }

    s.index = index

    return result
}


The C macros BITSTREAM_READER_LE and UNCHECKED_BITSTREAM_READER aren't available in Go. I've replaced it with "bitstreamReaderLE" and "uncheckedBitstreamReader".

In real use, these would be some configuration setting or global constant which you would define elsewhere. Remember that capitalizing the first letter of a variable or function in Go exports it.

Go doesn't support unsigned int as a type. The unsigned integer types available include uint, uint8, uint16, uint32, uint64. Depending on what you're trying to accomplish, you can change the return and type of variables from uint to one of these. Remember you can't mix types in Go.