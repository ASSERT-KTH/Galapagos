static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = (s->index)++;
    uint8_t result = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= (index & 7);
    result = result & 0x01;
#else
    result <<= (index & 7);
    result >>= (8 - 1);
    result = result & 0x01;
#endif
    
#if !UNCHECKED_BITSTREAM_READER
    if ((s->index) - 1 < s->size_in_bits_plus8)
        return result;

    s->index -= 1;
    return 0;
#else
    return result;
#endif
}