static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int place = s->index;
    uint8_t answer     = s->buffer[place >> 3];
#ifdef BITSTREAM_READER_LE
    answer >>= place & 7;
    answer  &= 1;
#else
    answer <<= place & 7;
    answer >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        place++;
    s->index = place;

    return answer;
}