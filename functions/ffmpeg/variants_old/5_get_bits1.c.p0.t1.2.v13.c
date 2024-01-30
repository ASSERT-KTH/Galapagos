static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int locator = s->index;
    uint8_t ans      = s->buffer[locator >> 3];

#ifdef BITSTREAM_READER_LE
    ans >>= locator & 7;
    ans &= 1U;
#else
    ans <<= locator & 7;
    ans >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8 - 1)
#endif
        locator++;
    s->index = locator;

    return (unsigned int) ans;
}