static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    unsigned int offset = index >> 3;
    uint8_t result = s->buffer[offset];

#ifdef BITSTREAM_READER_LE
    unsigned int subIndex = index & 7;
    result = (result >> subIndex) & 1;
#else
    result = (result << (index & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    bool check = s->index < s->size_in_bits_plus8;
    index += check ? 1 : 0;
#else
    index++;
#endif

    s->index = index;

    return result;
}