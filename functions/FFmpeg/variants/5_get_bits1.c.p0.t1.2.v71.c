static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result_pack     = s->buffer[index >> 3];
    uint8_t result = 0;
#ifdef BITSTREAM_READER_LE
    result = result_pack;
    result = result >> (index & 7);
    result = result & 1;
#else
    result = result_pack;
    result = result << (index & 7);
    result = result >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index = ++index;
    else
        s->index = index;
#else
    s->index = ++index;
#endif
    return result;
}