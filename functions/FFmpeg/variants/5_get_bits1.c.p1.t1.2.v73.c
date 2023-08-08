static inline unsigned int get_bits1(GetBitContext *s)
{
#ifndef BITSTREAM_READER_LE
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

    result <<= index & 7;
    result >>= 8 - 1;

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        index++;
#endif

    s->index = index;
    return result;

#else
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

    result >>= index & 7;
    result  &= 1;
    
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        index++;
    s->index = index;
#endif
    return result;

#endif
}
