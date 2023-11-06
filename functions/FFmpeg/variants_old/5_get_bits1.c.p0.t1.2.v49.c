static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int position = s->index;
    uint8_t returnValue   = s->buffer[position >> 3];
#ifdef BITSTREAM_READER_LE
    returnValue >>= position & 7;
    returnValue  &= 1;
#else
    returnValue <<= position & 7;
    returnValue >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        position += 1;
    s->index = position;

    return returnValue;
}