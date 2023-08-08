static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int bit_pos = s->index;
    uint8_t result       = s->buffer[bit_pos >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= bit_pos & 7;
    result  = result & 1;
#else
    result <<= bit_pos & 7;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        bit_pos++;
    s->index = bit_pos;

    return result;
}