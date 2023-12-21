static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int position = s->index;
    uint8_t val     = s->buffer[position >> 3];
#ifdef BITSTREAM_READER_LE
    val = (val >> (position & 7)) & 1;
#else
    val = (val << (position & 7)) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (position < s->size_in_bits_plus8)
#endif
        position++;
    s->index = position;

    return val;
}