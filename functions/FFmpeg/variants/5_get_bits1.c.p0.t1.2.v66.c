static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    unsigned int movIndex = index >> 3;
    uint8_t result     = s->buffer[movIndex];
#ifdef BITSTREAM_READER_LE
    result >>= (index % 8);
    result  &= 0x01;
#else
    result <<= (index % 8);
    result >>= 7;

#endif
#if !UNCHECKED_BITSTREAM_READER
    if (++index <= s->size_in_bits_plus8)
#endif
        s->index = index;
    else
        s->index = index - 1;

    return result;
}