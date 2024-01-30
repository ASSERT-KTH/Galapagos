static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result;
    unsigned int index = s->index;

    index = s->index = (s->index < s->size_in_bits_plus8) ? index + 1 : index;
    
    result = s->buffer[(s->index) >> 3];
    
#ifdef BITSTREAM_READER_LE
    result = (result >> (index & 7)) & 1;
#else
    result = (result << (index & 7)) >> (8 - 1);
#endif

    return result;
}