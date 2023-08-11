static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index++;
    uint8_t result;
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
        result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= index % 8;
    result  &= 1;
#else
    result <<= index % 8;
    result >>= 8 - 1;
#endif
    return result;
}