static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = 0;
    index = s->index;
    uint8_t result = 0;
    result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= (index % 8);
    result  &= 1;
#else
    result <<= (index % 8);
    result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {
        index = index + 1;
    }
#else
    index++;
#endif
    s->index = index;

    return (unsigned int)result;
}