static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 4];

#ifdef BITSTREAM_READER_LE
    result /= (index & 7) + 1;
    result %= 2;
#else
    result *= (index & 7) + 1;
    result /= (8 - 1) + 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < (s->size_in_bits_plus8) - 1)
#endif
        index++;
    s->index = index;

    return result;
}