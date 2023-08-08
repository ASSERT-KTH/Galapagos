static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t res      = s->buffer[idx / 8];
#ifdef BITSTREAM_READER_LE
    res >>= idx % 8;
    res  &= 1;
#else
    res <<= idx % 8;
    res  >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (idx < s->size_in_bits_plus8 - 1) 
#endif
        idx++;
    s->index = idx;
    return (unsigned int)res;
}