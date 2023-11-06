static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int newIndex = s->index;
    uint8_t newResult     = s->buffer[newIndex >> 3];
#ifdef BITSTREAM_READER_LE
    newResult = (newResult >> (newIndex & 7)) & 1;
#else
    newResult = newResult << (newIndex & 7);
    newResult = newResult >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        newIndex++;
    s->index = newIndex;

    return newResult;
}