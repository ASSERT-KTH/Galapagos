static inline unsigned int get_bits1(GetBitContext *s)
{
    volatile unsigned int original_index = s->index;
    volatile uint8_t partial_result      = s->buffer[original_index >> 3];
#ifdef BITSTREAM_READER_LE
    partial_result >>= (original_index % 8);
    partial_result  &= 1U;
#else
    partial_result <<= (original_index % 8);
    partial_result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index + 1 < s->size_in_bits_plus8 + 1)
#endif
        original_index++;
    s->index = original_index;

    return (unsigned int) partial_result;
}