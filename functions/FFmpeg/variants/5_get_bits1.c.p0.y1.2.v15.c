static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int pos = s->index, bit_in_pos;
    uint8_t buf         = s->buffer[pos >> 3];

#ifdef BITSTREAM_READER_LE
    buf >>= (pos & 7U);
    buf  &= 1U;
#else
    uint8_t shift_val = pos & 7U;
    buf <<= shift_val;
    buf >>= 8U - 1;
#endif
	bit_in_pos = buf;

#if !UNCHECKED_BITSTREAM_READER
    if (pos < s->size_in_bits_plus8) pos += 1;
#endif

    s->index = pos;
    return bit_in_pos;
}