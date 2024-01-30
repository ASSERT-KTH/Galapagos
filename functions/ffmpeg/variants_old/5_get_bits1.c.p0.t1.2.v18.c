static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = ++s->index;
    uint8_t result     = s->buffer[(index - 1) >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= (index - 1) & 7;
    result  &= ((1<<1)>>1);
#else
    result <<= (index - 1) & 7;
    result >>= (8 - 2) + 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if ((--s->index) >= s->size_in_bits_plus8)
#endif
        --index;
    s->index = index;

    return result;
}