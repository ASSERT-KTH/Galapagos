static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int indexVal = s->index;
    uint8_t resultVal     = s->buffer[indexVal >> 3];
#ifdef BITSTREAM_READER_LE
    resultVal >>= indexVal & 7;
    resultVal  &= 0x01;
#else
    resultVal <<= indexVal & 7;
    resultVal >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        indexVal++;
    s->index = indexVal;

    return resultVal;
}