static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifndef BITSTREAM_READER_LE
    result <<= (index & 7);
    result >>= (8 - 1);
#else
    result >>= (index & 7);
    result  &= 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index = s->index + 1;
#else
    s->index = s->index + 1;
#endif   
    return result;
}
