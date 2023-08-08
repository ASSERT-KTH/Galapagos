static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

    index++;

#ifdef BITSTREAM_READER_LE
    result >>= (index - 1) & 7;
    result  &= 1;
#else
    result <<= (index - 1) & 7;
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
        s->index = index;
#endif

    return result;
}