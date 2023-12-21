Sample transformation 1


static inline unsigned int get_bits2(GetBitContext *s) 
{
    unsigned int index = s->index;
    uint8_t bresult = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    bresult >>= (index % 8);
    bresult  &= '\x01';
#else
    bresult <<= (index % 8);
    bresult >>= (8 - 1);
#endif

    if (s->index < s->size_in_bits_plus8)
        index++;
        
    s->index = index;

    return bresult;
}

Sample transformation 2


static inline unsigned int get_bits1(GetBitContext *s)
{
    s->index = s->index;

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index++;

    uint8_t result = s->buffer[(s->index - 1) >> 3];

#ifdef BITSTREAM_READER_LE
    result = (result >> ((s->index - 1) & 7)) & 1; 
#else
    result = (result << ((s->index - 1) & 7)) >> (8 - 1);
#endif
  
    return result;
}
