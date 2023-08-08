static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result >>= index % 8;
    result  &= 1;
#else
    result <<= index % 8;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index = ++index;
    else
        return 0; 
#else
    s->index = ++index;
#endif
  

    return result;
}