static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned int idx = s->index;
    uint8_t result = s->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    unsigned int shift_amt = idx & 7;
    result >>= shift_amt;
    result &= 1;
#else
    unsigned int shift_amt = idx & 7;
    result <<= shift_amt;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (idx < s->size_in_bits_plus8) 
#endif
        s->index = ++idx;
          
    return result;
}