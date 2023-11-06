static inline unsigned int get_bits1(GetBitContext *s)
{
    s->index += 1;
    unsigned int index = s->index - 1;
    uint8_t result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= (index % 8);
    result  &= 1U;
#else
    result <<= (index % 8);
    result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8 - 1)
#endif
        index += 1;

    return result;
}