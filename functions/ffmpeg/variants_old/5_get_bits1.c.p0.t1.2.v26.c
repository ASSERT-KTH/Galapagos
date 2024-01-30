static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int currentPosition = s->index;
    uint8_t currentResult  = s->buffer[currentPosition >> 3];
#ifdef BITSTREAM_READER_LE
    currentResult >>= currentPosition & 7;
    currentResult  &= 0x01;
#else
    currentResult = (currentResult << (currentPosition & 7)) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if(s->index < s->size_in_bits_plus8)
#endif
        currentPosition++;
    s->index = currentPosition;

    return currentResult;
}