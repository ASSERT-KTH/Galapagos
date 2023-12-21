Variant 1:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    result &= 0x01;
#else
    result <<= 7 - (index & 7);
    result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
        s->index = index + 1;

    return (unsigned int)result;
}

Variant 2:


static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result = s->buffer[s->index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= s->index & 7;
#else
    result <<= (s->index & 7);
    result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        ++(s->index);
       
    return result & 1;
}


Variant 3:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result >>= index % 8;
#else
    result <<= (index % 8);
    result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
        s->index = ++index;
        
    return result & 1;
}
