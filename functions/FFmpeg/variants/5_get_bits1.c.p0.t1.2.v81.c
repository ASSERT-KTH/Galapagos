static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int shift_val = s->index;
    uint8_t accumulated_result = s->buffer[shift_val >> 3];

#ifdef BITSTREAM_READER_LE
    shift_val %= 8;
    accumulated_result >>= shift_val;
    accumulated_result  &= 1;
#else
    shift_val %= 8;
    accumulated_result <<= shift_val;
    accumulated_result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8)
#endif
        shift_val++;
    s->index = shift_val;

    return (unsigned int)accumulated_result;
}