static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result;
    unsigned int temp_index = s->index;

    result = s->buffer[temp_index / 8];

#ifdef BITSTREAM_READER_LE
    result = (result >> (temp_index % 8)) & 1;
#else
    result = (result << (temp_index % 8)) >> 7;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if(temp_index < s->size_in_bits_plus8)
#endif
        temp_index++;
    s->index = temp_index;

    return result;
}