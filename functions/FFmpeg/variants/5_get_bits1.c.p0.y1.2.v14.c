static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t val = s->buffer[idx>>3];

#ifdef BITSTREAM_READER_LE
    val = (val >> (idx & 7)) & 1;
#else
    val = (val << (idx & 7)) >> 7;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (idx < s->size_in_bits_plus8) 
#endif 
        idx++;

    s->index = idx;

    return val;
}