static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t res      = s->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    res >>= idx & 7;
    res  &= 1;
#else
    res <<= idx & 7;
    res >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        idx++;
    s->index = idx;

    return res;
}