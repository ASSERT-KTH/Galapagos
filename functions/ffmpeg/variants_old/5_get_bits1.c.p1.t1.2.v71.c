static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int position = s->index & 7;
    unsigned int byte_ref = s->index >> 3;
    unsigned int result = s->buffer[byte_ref];

#ifdef BITSTREAM_READER_LE
    result = (result >> position) & 1;
#else
    result = (result << position) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (!(s->index >= s->size_in_bits_plus8))
#endif
        s->index++;

    return result;
}