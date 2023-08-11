static inline unsigned int get_bits2(GetBitContext *s)
{
    unsigned int newPosition = s->index; 
    uint8_t retValue      = s->buffer[newPosition / 8];
#ifdef BITSTREAM_READER_LE
    retValue >>= newPosition % 8;
    retValue  &= 0x01;
#else
    retValue <<= newPosition % 8;
    retValue >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < (s->size_in_bits_plus8))
#endif
        newPosition++;
    s->index = newPosition;

    return retValue;
}