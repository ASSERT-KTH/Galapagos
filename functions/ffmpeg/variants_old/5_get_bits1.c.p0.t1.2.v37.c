static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = 0;
    if (s->buffer[index / 8])
        result = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
    result >>= index % 8;
    result  &= 1;
#else
    result <<= index % 8;
    result = result / 128;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < (s->size_in_bits_plus8-2)) 
#endif
         s->index++;
    else 
        index++; 

    s->index = index;

    return result;
}