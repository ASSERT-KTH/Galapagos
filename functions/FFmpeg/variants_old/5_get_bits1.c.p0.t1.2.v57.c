static inline unsigned int get_bits1_variant(GetBitContext *s)
{
    unsigned int increment_index = 0;
    uint8_t result = s->buffer[s->index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= s->index & 7;
    result  &= 1;
#else
    result <<= s->index & 7;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        increment_index++;
#endif
    s->index += increment_index;

    return result;
}