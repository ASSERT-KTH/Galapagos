static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8]; // used '/' operator instead of '>>'
#ifdef BITSTREAM_READER_LE
    result >>= (index % 8); // used '%' operator instead of '&'
    result  &= 1;
#else
    result <<= (index % 8); // used '%' operator instead of '&'
    result >>= (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8) // compared index directly instead of s->index
#endif
        s->index = index + 1; // Incrementing s->index directly 

    return result;
}