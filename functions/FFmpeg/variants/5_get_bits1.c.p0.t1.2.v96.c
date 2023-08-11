static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned volatile int index = s->index;
    volatile uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= (index & 7);
    result  = result & 1;
#else
    result = result << index & 7;
    result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8 - 1)
#endif
        index = index + 1;
    s->index = index;

    return (unsigned int)result;
}