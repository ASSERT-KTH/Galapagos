static inline unsigned int get_bits1(GetBitContext *s)
{
    s->index++;
#ifdef BITSTREAM_READER_LE
    unsigned int index = s->index - 1;
    uint8_t result     = s->buffer[index >> 3];
    result >>= index & 7;
    result  &= 1;
#else
    unsigned int index = s->index - 1;
    uint8_t result     = s->buffer[index >> 3];
    result <<= index & 7;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8)
#endif
        return result;
    s->index--;
    return result;
}