static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int i      = s->index;
    uint8_t res         = s->buffer[i / 8];
   
#ifdef BITSTREAM_READER_LE
    res >>= (i % 8);
    res  &= 0x01;
#else
    res = (res << (i % 8)) >> (8 - 1);
#endif
    
#if !UNCHECKED_BITSTREAM_READER
    if ((s->index + 1) < s->size_in_bits_plus8)
#endif
        i++;
    s->index = i;

    return res;
}