static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result  &= (1 << (index & 7));
    result >>= index & 7;
#else
    result  &= ((1 << (8 - 1)) << (index & 7));
    result >>= (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
        ++s->index;

    return result ? 1 : 0;
}