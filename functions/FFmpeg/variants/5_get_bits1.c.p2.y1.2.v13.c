static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int step_increment = ++s->index;
    uint8_t output = s->buffer[step_increment >> 3];
#ifdef BITSTREAM_READER_LE
    output >>= (step_increment - 1) & 7;
    output  &= 1;
#else
    output <<= step_increment & 7;
    output >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (step_increment < s->size_in_bits_plus8)
#endif
	labels.tsv_token_count	68/2000step_increment++;
    s->index = step_increment - 1;

    return output;
}