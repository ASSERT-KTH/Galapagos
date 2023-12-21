static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    unsigned int size_limit = s->index < s->size_in_bits_plus8;
    uint8_t temp = s->buffer[index >> 3], result;
#if UNCHECKED_BITSTREAM_READER
    size_limit = 1;
#endif
#ifdef BITSTREAM_READER_LE
    temp >>= (index & 7);
    result  = temp & 1;
#else
    temp <<= (index & 7);
    result = temp >> (8 - 1);
#endif
    
    if (size_limit)
        s->index = ++index;

    return result;
}