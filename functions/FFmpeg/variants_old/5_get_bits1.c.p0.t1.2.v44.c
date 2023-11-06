static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index + 1;
    uint8_t result;
#ifdef BITSTREAM_READER_LE
    result = s->buffer[(index-1) >> 3] >> ((index-1) & 7) & 1;
#else
    result = s->buffer[(index-1) >> 3] << ((index-1) & 7) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index - 1 < s->size_in_bits_plus8) {
        s->index = index;
    }
#else
    s->index = index;
#endif    
    return result;  
}