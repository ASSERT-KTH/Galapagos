static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index++;
#ifdef BITSTREAM_READER_LE
    uint8_t result = (s->buffer[index >> 3] >> (index & 7)) & 1;
#else
    uint8_t result = (s->buffer[index >> 3] << (index & 7)) >> 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index >= s->size_in_bits_plus8)
        s->index--;
#endif
    return result;
}