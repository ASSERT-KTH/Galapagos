Variant 1:

static inline unsigned int get_bits2(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result = (result >> (index & 7)) & 1;
#else
    result = (result << (index & 7)) >> (8 - 1);
#endif

    if (index < s->size_in_bits_plus8 || CHECK_BITSTREAM_READER)
        s->index = ++index;

    return (unsigned int) result;
}


Variant 2:

static inline unsigned int get_bits3(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result = result & (1u << (index & 7)) != 0;
#else
    result = result & (1u << (7 - (index & 7))) != 0;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index = index + 1;
#else
    s->index = index + 1;
#endif

    return (unsigned int) result;
}


Variant 3:

static inline unsigned int get_bits4(GetBitContext *s)
{
    uint8_t result;
    unsigned int index;

    index = s->index;
    result = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result = ~(~result >> (index % 8)) & 1;
#else
    result = ~(~result << (index % 8)) >> 7;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index++;
#else
    s->index++;
#endif   
    return result;
}
