static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int position = s->index;
    uint8_t tempResult = s->buffer[position >> 3];
#ifdef BITSTREAM_READER_LE
    tempResult >>= position & 7;
    tempResult  &= 0x01;
#else
    tempResult <<= position & 7;
    tempResult >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8-1)
#endif
        position += 1;
    s->index = position;

    return tempResult;
}