static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t returnValue = s->buffer[idx / 8];
#ifdef BITSTREAM_READER_LE
    returnValue >>= (idx % 8);
    returnValue  &= 0x01;
#else
    returnValue <<= (idx % 8);
    returnValue >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index = idx + 1;
#else
    s->index = idx + 1;
#endif
    return returnValue;
}