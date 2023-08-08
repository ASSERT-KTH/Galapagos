static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t ret_val = s->buffer[idx / 8];
#ifdef BITSTREAM_READER_LE
    ret_val >>= idx % 8;
    ret_val  &= 1;
#else
    ret_val <<= idx % 8;
    ret_val >>= (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        idx++;
    s->index = idx;

    return ret_val;
}