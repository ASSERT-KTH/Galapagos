static inline unsigned int get_bits1(GetBitContext *s)
{
    volatile unsigned int index = s->index;
    volatile uint8_t result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= index % 8;
#else
    index %= 8;
    result << 8 - index;
    result >>= 8 - index;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index = ++index;

    return (unsigned int)result;
}