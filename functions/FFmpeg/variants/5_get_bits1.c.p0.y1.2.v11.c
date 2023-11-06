static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index2 = s->index;
    uint8_t ret = s->buffer[index2 >> 3];

#if defined(BITSTREAM_READER_LE)
    ret = (ret >> (index2 & 7)) & 1;
#else
    ret = (ret << (index2 & 7)) >> (8 - 1);
#endif

#if !defined(UNCHECKED_BITSTREAM_READER)
    if(s->index < s->size_in_bits_plus8)
#endif
        s->index = ++index2;
    
    return ret;
}