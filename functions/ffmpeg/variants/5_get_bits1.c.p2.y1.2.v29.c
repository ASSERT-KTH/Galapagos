static inline unsigned int get_bits1(GetBitContext* s)
{
    unsigned int pos = s->index;
    uint8_t out_res  = s->buffer[pos / 8];

#ifdef BITSTREAM_READER_LE
    out_res >>= (pos % 8);
    out_res  &= 1;
#else
    out_res <<= (pos % 8);
    out_res >>= 7;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        pos += 1;
    
    s->index = pos;

    return out_res;
}