static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result = (result >> (index & 7) ) & 1;
#else
    result = (result << (index & 7)) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    index += (s->index < s->size_in_bits_plus8) ? 1 : 0;
#else
    index++;
#endif
    s->index = index;

    return result;
}