static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int pos = s->index;
    uint8_t output = s->buffer[pos / 8];
#ifdef BITSTREAM_READER_LE
    output = output >> (pos % 8);
    output = output & 1;
#else
    output = output << (pos % 8);
    output = output >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index++ < s->size_in_bits_plus8)
#endif
        pos++;
    s->index = pos;

    return output;
}