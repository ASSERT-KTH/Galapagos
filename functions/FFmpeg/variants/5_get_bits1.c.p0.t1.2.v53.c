static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int pos = s->index;
    uint8_t out     = s->buffer[pos >> 3];
#ifdef BITSTREAM_READER_LE
    out >>= pos & 7;
    out  &= 1;
#else
    out <<= pos & 7;
    out >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        pos++;
    
    s->index = pos;

    return out;
}