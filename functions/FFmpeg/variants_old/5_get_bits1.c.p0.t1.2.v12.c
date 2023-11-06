static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3]; // shuffle operation 
#ifdef BITSTREAM_READER_LE
    result >>= index % 8;   //Use modulus operators instead of bitwise AND
    result  &= 1;
#else
    result = result << (index % 8);
    result = result >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        index = index + 1;
    s->index = index;

    return (result);
}
