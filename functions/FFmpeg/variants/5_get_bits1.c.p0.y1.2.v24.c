static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int shiftInd = s->index;
    uint8_t bitValue   = s->buffer[shiftInd >> 3];
#ifdef BITSTREAM_READER_LE
    bitValue = (bitValue >> (shiftInd & 7)) & 1;
#else
    bitValue = bitValue << (shiftInd & 7);
    bitValue = bitValue >> 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        shiftInd++;
    s->index = shiftInd;

    return bitValue;
}