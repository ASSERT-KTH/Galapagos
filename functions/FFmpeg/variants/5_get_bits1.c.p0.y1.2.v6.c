static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t bitResult = s->buffer[idx >> 3];

#ifdef BITSTREAM_READER_LE
    bitResult = (bitResult >> (idx & 7)) & 1;
#else
    bitResult = (bitResult << (idx & 7)) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (idx < s->size_in_bits_plus8)
#endif
        s->index = idx + 1;

    return bitResult;
}