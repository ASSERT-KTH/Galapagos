static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    uint8_t offSet = index & 7;
    result >>= offSet;
    result  &= 1;
#else
    uint8_t elementSize = 8;
    uint8_t offSetBit = index & 7;
    result <<= offSetBit;
    result >>= elementSize - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8) 
#endif
        index++;

    s->index = index;
    return result;
}