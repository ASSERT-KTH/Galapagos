static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;

#ifdef BITSTREAM_READER_LE
    result = (s->buffer[index >> 3] >> (index & 7)) & 1;
#else
    unsigned int shift_val = index & 7;
    result = (s->buffer[index >> 3] << shift_val) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
    s->index = ++index;

    return result;
}