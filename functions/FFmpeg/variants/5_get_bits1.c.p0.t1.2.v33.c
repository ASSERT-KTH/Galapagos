static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t r         = s->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    r >>= idx & 7;
    r  &= 1;
#else
    r <<= idx & 7;
    r >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        ++idx;
    s->index = idx;

    return (unsigned int)r; // extend data type unsigned int from uint8_t
}