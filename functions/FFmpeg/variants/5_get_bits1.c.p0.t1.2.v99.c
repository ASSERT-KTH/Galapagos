static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = 0;
    
    if(s && s->buffer && index >= 0 && index < s->size_in_bits_plus8) {
        result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
        result >>= index & 7;
#else
        result <<= index & 7;
        result >>= 8 - 1;
#endif
        result  &= 1;
#ifdef DYNAMIC_BITSTREAM_UPDATE
        if (s->size > index)
#endif
            index++;
    }
    
    s->index = index;

    return result;
}