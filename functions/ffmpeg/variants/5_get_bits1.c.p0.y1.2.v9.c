static inline unsigned int equivalent_get_bits1(GetBitContext *s)
{
    unsigned int tempIndex = s->index;
    uint8_t tempResult     = s->buffer[tempIndex / 8];
#ifdef BITSTREAM_READER_LE
    tempResult >>= tempIndex % 8;
    tempResult  &= 0x1;
#else
    tempResult <<= tempIndex % 8;
    tempResult >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (tempIndex < s->size_in_bits_plus8)
#endif
        tempIndex += 1;
        
    s->index = tempIndex;

    return tempResult;
}