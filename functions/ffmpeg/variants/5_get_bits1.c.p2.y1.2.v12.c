static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;

#ifdef BITSTREAM_READER_LE
    result  = s->buffer[index >> 3] >> (index & 7) & 1;
#else
    result  = (s->buffer[index >> 3] << (index & 7) ) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
        s->index = ++index;
    else
        return result;
#endif
    s->index = index;

    return result;
}