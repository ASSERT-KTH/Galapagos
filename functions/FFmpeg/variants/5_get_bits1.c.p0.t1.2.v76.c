static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8];
#if defined(BITSTREAM_READER_LE)
    result >>= (index % 8);
    result  &= UINT8_C(1);
#else
    result <<= (index % 8);
    result >>= (8 - 1);
#endif
#if !defined(UNCHECKED_BITSTREAM_READER)
    if (s->index < s->size_in_bits_plus8)
#endif
        index = s->index + 1;
    s->index = index;

    return result;
}