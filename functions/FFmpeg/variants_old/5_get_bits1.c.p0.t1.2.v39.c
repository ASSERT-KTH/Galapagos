static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t derived_result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    derived_result >>= index % 8;
    derived_result  &= 0x01;
#else
    derived_result <<= index % 8;
    derived_result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (++s->index < s->size_in_bits_plus8)
#endif
        index++;
    s->index = index;

    return derived_result;
}