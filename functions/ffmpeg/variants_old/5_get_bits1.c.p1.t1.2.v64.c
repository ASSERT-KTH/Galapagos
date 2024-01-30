static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int original_index = s->index;
    uint8_t result     = s->buffer[original_index >> 3];

#ifdef BITSTREAM_READER_LE
    unsigned int offset = original_index & 7;  
    result >>= offset;
    result  &= 1;
#else
    unsigned int shift = original_index & 7;  
    result <<= shift;
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (original_index < s->size_in_bits_plus8)
#endif
    original_index++;
    
    s->index = original_index;

    return result;
}