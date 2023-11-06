static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#if defined BITSTREAM_READER_LE

    result = (result >> (index & 7)) & 1;

#elif defined BITSTREAM_READER_BE

    result = (result << (index & 7)) >> (8 - 1);

#endif

#if defined ALLOW_BITSTREAM_OVERFLOW
    if ((s -> index) < s -> size_in_bits_plus8)
#endif

    s->index = index + 1;

    return result;
}