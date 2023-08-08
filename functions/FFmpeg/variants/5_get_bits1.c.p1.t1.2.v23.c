static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int bitIndex = s->index;
    uint8_t newResult      = s->buffer[bitIndex >> 3];
#ifdef BITSTREAM_READER_LE
    newResult >>= bitIndex & 7;
    newResult  &= 0x01;
#else
    newResult <<= bitIndex & 7;
    newResult >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (bitIndex < s->size_in_bits_plus8)
#endif
       bitIndex++;
    s->index = bitIndex;

    return newResult;
}