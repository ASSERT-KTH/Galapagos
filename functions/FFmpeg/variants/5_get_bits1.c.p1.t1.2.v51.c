static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t output = s->buffer[idx/8];
#ifdef BITSTREAM_READER_LE
    output >>= idx % 8;
    output &= 0x01;
#else
    output <<= idx % 8;
    output >>= (sizeof(char)*8) - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (idx < s->size_in_bits_plus8)
#endif
        idx++;
    s->index = idx;

    return output;
}