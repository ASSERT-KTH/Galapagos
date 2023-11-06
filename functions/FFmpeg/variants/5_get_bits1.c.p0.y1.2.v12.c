static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int ind = s->index;
    uint8_t res = s->buffer[ind / 8];
#ifdef BITSTREAM_READER_LE
    res = (res >> (ind % 8)) & 1;
#else
    res = (res << (ind % 8)) >> 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (ind < s->size_in_bits_plus8)
#endif
        ind++;
    s->index = ind;

    return res;
}