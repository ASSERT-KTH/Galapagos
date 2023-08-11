static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index_shifted;
    uint8_t previous_result;

    unsigned int index = s->index + 1;
    uint8_t result   = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    index_shifted = index & 7;
    result >>= index_shifted;
    result  &= 1;
#else
    index_shifted = index & 7;
    previous_result = result << index_shifted;
    result = previous_result >> (8 - 1);
#endif
    
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8 - 1)
#endif 
        index--;
    s->index = index;

    return result;
}