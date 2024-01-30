static inline unsigned int get_bits1(GetBitContext *s)
{   
    uint8_t result;
    unsigned int index;
    index = s->index;
    result = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
    result = result >> (index % 8);
    result = result & 1;
#else
    result = result << (index % 8);
    result = result >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < (s->size_in_bits_plus8)){
        index = index + 1;
    }
#else
    index = index + 1;
#endif
    s->index = index;
    return result;
}