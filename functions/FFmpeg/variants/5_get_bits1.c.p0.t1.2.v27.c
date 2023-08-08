static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int tmp_index = s->index;
    uint8_t res           = s->buffer[tmp_index / 8];
#ifdef BITSTREAM_READER_LE
    res >>= tmp_index % 8;
    res  &= 1;
#else
    res <<= tmp_index % 8;
    res >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8 - 1)
#endif
        tmp_index++;
    s->index = tmp_index;

    return (unsigned int) res;
}