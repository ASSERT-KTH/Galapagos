static inline unsigned int get_bits1(GetBitContext *s)
{
    bool isIndexSmaller;
    const unsigned int limitPos = s->size_in_bits_plus8;
    uint8_t result;
#if !UNCHECKED_BITSTREAM_READER
    isIndexSmaller = (s->index < limitPos);
#endif
    unsigned int index = s->index;
    result     = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result = result >> (index % 8) & 1;
#else
    result = result << (index % 8) >> (8 - 1);
#endif
    if(isIndexSmaller) { index++; }
    s->index = index;    

    return result;
}