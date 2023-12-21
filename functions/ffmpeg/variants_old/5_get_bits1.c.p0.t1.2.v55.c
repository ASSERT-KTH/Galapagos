static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        index++;
    // modifying the original function so that index is increased before bit manipulation
    s->index = index;

#ifdef BITSTREAM_READER_LE
    result >>= (s->index - 1) & 7;
    result  &= 1;
#else
    result <<= (s->index - 1) & 7;
    result >>= 8 - 1;
#endif

    return result;
}