static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t retVal  = s->buffer[idx >> 3];

#ifdef BITSTREAM_READER_LE
    retVal = retVal >> (idx & 7);
    retVal = retVal & 0x01;
#else
    retVal = retVal << (idx & 7);
    retVal = (retVal >> 7) & 0x01;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (idx < s->size_in_bits_plus8)
#endif
        idx++;
    s->index = idx;

    return retVal;
}