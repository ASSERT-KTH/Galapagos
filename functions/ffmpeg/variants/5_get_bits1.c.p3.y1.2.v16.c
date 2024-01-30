func getBits1(s *GetBitContext) uint {
    index := s.index
    var result uint8 = s.buffer[index >> 3]
    #ifdef BITSTREAM_READER_LE
        result >>= index & 7
        result &^= 1
    #else
        result <<= index & 7
        result >>= 8 - 1
    #endif
    #if !UNCHECKED_BITSTREAM_READER
        if s.index < s.sizeInBitsPlus8 {
            index++
        }
    #endif
    s.index = index

    return uint(result)
}