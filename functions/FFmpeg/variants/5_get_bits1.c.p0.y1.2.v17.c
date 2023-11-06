static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int indx = s->index;
    uint8_t res   = s->buffer[indx >> 3];
#ifdef BITSTREAM_READER_LE
    res = (res >> (indx & 7)) & 1;
#else
    res = (res << (indx & 7)) >> 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (indx < s->size_in_bits_plus8)
#endif
        indx++;
    s->index = indx;

    return res;
}