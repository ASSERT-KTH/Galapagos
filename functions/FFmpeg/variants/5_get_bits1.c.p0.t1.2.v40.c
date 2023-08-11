static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int pos = s->index;
    uint8_t temp     = s->buffer[pos >> 3];
#ifdef BITSTREAM_READER_LE
    temp >>= pos & 7;
    temp  &= 0x01;
#else
    temp <<= pos & 7;
    temp >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        pos++;
    s->index = pos;

    return temp;
}