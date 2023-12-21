static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int tmp_index = s->index;
    uint8_t tmp_result     = s->buffer[tmp_index / 8];

#ifdef BITSTREAM_READER_LE
    tmp_result = tmp_result >> (tmp_index % 8);
    tmp_result = tmp_result & 1;
#else
    tmp_result = tmp_result << (tmp_index % 8);
    tmp_result = tmp_result >> 7;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        tmp_index++;

    s->index = tmp_index;

    return tmp_result;
}