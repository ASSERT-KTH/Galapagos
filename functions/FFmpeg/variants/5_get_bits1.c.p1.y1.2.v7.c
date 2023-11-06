Variant 1:

static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int index = s->index, result;
   
    result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result = (result >> (index & 7)) & 1;
#else
    result = result << (index & 7) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
        s->index = ++index;
    return result;
}

Variant 2:

static inline unsigned int get_bits1(GetBitContext *s) {
    uint8_t result = s->buffer[s->index >> 3];

#ifdef BITSTREAM_READER_LE
    result = (result >> (s->index & 7)) & 1;
#else
    result = result << (s->index & 7) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index++;

    return result;
}


Variant 3:

static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int index  = s->index;
    unsigned int offset = index & 7;
    
    uint8_t result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result = (result >> offset) & 1;
#else
    result = result << offset >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
        index++;

    s->index = index;

    return result;
}
