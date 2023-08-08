static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int position = s->index;
    uint8_t bit_string    = s->buffer[position >> 3];

#ifdef BITSTREAM_READER_LE
    bit_string >>= position & 7;
    bit_string  &= 1;
#else
    bit_string <<= position & 7;
    bit_string >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (position < s->size_in_bits_plus8)
#endif
        s->index++;
    
    return bit_string;
}