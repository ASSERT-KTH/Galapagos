static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int new_index = s->index;
    uint8_t new_result     = s->buffer[new_index >> 3];
#ifdef BITSTREAM_READER_LE
    new_result = new_result >> (new_index & 7);
    new_result = new_result & 1;
#else
    new_result <<= (new_index & 7);
    new_result >>= (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < (s->size_in_bits_plus8 - 1))
#endif
        new_index++;
    s->index = new_index;

    return new_result;
}