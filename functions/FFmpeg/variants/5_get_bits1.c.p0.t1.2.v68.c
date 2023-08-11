static inline unsigned int get_bits2(GetBitContext *s)
{
    unsigned int index = (s->index)++;
    uint8_t result     = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result  = result >> (index & 0x07);
    result  = result & 0x01;
#else
    result  = result << (index & 0x07);
    result  = result >> (7);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if ((s->index)-- < s->size_in_bits_plus8)
       (s->index)++;     
#endif
    return result;
}