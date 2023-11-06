static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index, result_temp;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result_temp = result;
    result      = result_temp >> (index & 7);
    result     &= 1;
#else
    result_temp = result;
    result      = result_temp << (index & 7);
    result     >>= (8 - 1);
#endif
    if (s->index < s->size_in_bits_plus8)
        index++;

    s->index = index;
    return result;
}