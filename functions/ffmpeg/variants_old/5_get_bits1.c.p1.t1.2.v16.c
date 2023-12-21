static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t rslt     = s->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    rslt >>= idx & 7;
    rslt  &= 1;
#else
    rslt <<= idx & 7;
    rslt >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (idx < s->size_in_bits_plus8)
#endif
        idx++;
    
    s->index = idx;

    return rslt;
}