static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    unsigned char result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= (index & 7);
    result  &= 0x01;
#else
    result <<= (index & 7);
    result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < (s->size_in_bits_plus8 - 1))
#endif
        index += 1;
    
    if(index < s->size_in_bits_plus8)
        s->index = index;
    else
        s->index = s->size_in_bits_plus8;

    return (unsigned int) result;
}