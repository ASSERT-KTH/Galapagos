static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    unsigned int result;

#ifdef BITSTREAM_READER_LE
    result = s->buffer[index / 8];
    result = result >> (index % 8) & 1;
#else
    result = s->buffer[index / 8];
    result = result << (index % 8);
    result = result >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index++;

    return result;
}