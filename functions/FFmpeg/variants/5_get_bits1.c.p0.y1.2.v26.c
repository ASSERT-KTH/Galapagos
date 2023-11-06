static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int position = s->index;
    uint8_t bit = s->buffer[position / 8];

#ifdef BITSTREAM_READER_LE
    bit >>= (position & 7);
    bit = bit  & 1;
#else
    bit <<= (position & 7);
    bit >>= 7;             
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (position < s->size_in_bits_plus8)
#endif
        position++;
    s->index = position;

    return bit;
}