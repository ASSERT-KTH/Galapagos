static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int my_index = s->index;
    uint8_t var_result    = s->buffer[my_index >> 3];

#ifdef BITSTREAM_READER_LE
    var_result     >>= my_index % 8;
    var_result     &= 1;
#else
    var_result     = (var_result << (my_index & 7)) >> 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8 - 1)
#endif
        my_index++;
        
    s->index = my_index;

    return (unsigned int) var_result;
}