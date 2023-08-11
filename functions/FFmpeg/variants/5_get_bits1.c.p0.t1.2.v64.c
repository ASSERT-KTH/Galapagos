static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int local_index = s->index;
    uint8_t result     = s->buffer[local_index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= (local_index & 7);
    result  &= (~(result-1));
#else
    result = result << (local_index & 7);
    result = result >> (9 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (local_index < s->size_in_bits_plus8)
#endif
        local_index = local_index + 1;
    s->index = local_index;

    return (result != 0);
}