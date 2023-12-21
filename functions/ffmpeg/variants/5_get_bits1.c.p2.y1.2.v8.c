static inline unsigned int get_bits1(GetBitContext *s)
{
#ifdef BITSTREAM_READER_LE
    uint8_t result = s->buffer[s->index >> 3] >> (s->index & 7) & 1;
    s->index++;
#else
    uint8_t result = s->buffer[s->index >> 3] << (s->index & 7) >> (8 - 1);
    s->index++;
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8)
#endif
#endif
    return result;
}