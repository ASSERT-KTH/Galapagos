static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int temp_index = s->index;
    uint8_t temp_result = s->buffer[temp_index >> 3];

#ifdef BITSTREAM_READER_LE
    temp_result = (temp_result >> (temp_index & 7)) & 1;
#else
    temp_result = (temp_result << (temp_index & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (temp_index < s->size_in_bits_plus8)
#endif
        temp_index++;

    s->index = temp_index;

    return temp_result;
}