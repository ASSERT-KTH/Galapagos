static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result = (result / (1 << (index % 8))) & 1;
#else
    result = (result << (index % 8)) / (1 << 7);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index = index + 1;

    return result;
}