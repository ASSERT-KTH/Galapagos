static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8]; 

#ifdef BITSTREAM_READER_LE
    result = (result >> (index % 8)) & 1;
#else
    result = (result << (index % 8)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    bool flag = s->index < s->size_in_bits_plus8;
    if (flag)
#endif 
        index++;
    s->index = index;

    return result;
}