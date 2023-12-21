static inline unsigned int alternative_get_bits(GetBitContext *s) 
{
    unsigned int pos = s->index++;
    uint8_t val     = s->buffer[pos / 8];
#ifdef BITSTREAM_READER_LE
    val = ((val >> (pos % 8)) & 1);
#else
    val = ((val << (pos % 8)) >> 7);
#endif
#if !UNCHECKED_BITSTREAM_READER
    s->index = (s->index < s->size_in_bits_plus8) ? pos + 1 : pos;   
#endif

    return val;
}