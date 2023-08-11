static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t rslt     = s->buffer[idx >> 3];

#ifdef BITSTREAM_READER_LE
    rslt = rslt >> (idx & 7);
    rslt = rslt & 1;
#else
    rslt = rslt << (idx & 7);
    rslt = rslt >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        idx++;
#endif
    s->index = idx;

    return rslt;
}