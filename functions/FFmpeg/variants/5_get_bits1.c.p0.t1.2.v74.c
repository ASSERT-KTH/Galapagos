static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int newIndex = 1 + s->index;
    uint8_t tmpResult = s->buffer[newIndex >> 3];
#ifdef BITSTREAM_READER_LE
    tmpResult >>= s->index & 7;
#else
    tmpResult <<= (s->index & 7);
    tmpResult = tmpResult >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (newIndex <= s->size_in_bits_plus8 - 1)
#endif
    newIndex++;
    s->index = newIndex - 1;
    return tmpResult & 1;
}