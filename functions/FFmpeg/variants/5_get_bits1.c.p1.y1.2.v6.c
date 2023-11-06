Variant 1:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result = (result >> (index & 7)) & 1;
#else
    result = (result << (index & 7)) >> (8 - 1);
#endif    
#if !UNCHECKED_BITSTREAM_READER
    s->index = (s->index < s->size_in_bits_plus8) ? index + 1 : index;
#else
    s->index = index + 1;
#endif
    return result;
}


Variant 2:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result  = result >> (index & 7);
    result  &= 0x01;
#else
    result  = result << (index & 7);
    result  >>= 0x07;
#endif 
#if !UNCHECKED_BITSTREAM_READER
    index += (s->index < s->size_in_bits_plus8) ? 1 : 0;
#endif
    s->index = index;

    return result;
}
 

Variant 3:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result &= (1 << (index & 7));
    result >>= (index & 7);
#else
    result >>= (8 - (index & 7) - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) index++;
#endif
    s->index = index;

    return result;
}
