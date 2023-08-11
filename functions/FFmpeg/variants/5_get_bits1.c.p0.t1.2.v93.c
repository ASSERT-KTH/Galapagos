static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int pos = s->index;
    uint8_t outcome  = s->buffer[pos / 8];
#ifdef BITSTREAM_READER_LE
    int offset = pos & 7;
    outcome = (outcome >> offset) & 1;
#else
    int shift_val = pos & 7;
    outcome = (outcome << shift_val) >> 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (pos < s->size_in_bits_plus8 - 1)
#endif
        pos++;
    s->index = pos;

    return (unsigned int)outcome;
}