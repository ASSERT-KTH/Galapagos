Solution 1:

static inline unsigned int get_bits1_variant1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#if defined BITSTREAM_READER_LE
    result = (result >> (index & 7) & 1);
#elif !defined BITSTREAM_READER_LE
    result = (result << (index & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
#endif
        s->index = index + 1;

    return result;
}


Solution 2:

static inline unsigned int get_bits1_variant2(GetBitContext *s)
{
    unsigned int index = s->index;
   
#if defined BITSTREAM_READER_LE
    uint8_t result = (s->buffer[index >> 3] >> (index & 7) & 1);
#elif !defined BITSTREAM_READER_LE
    uint8_t result = (s->buffer[index >> 3] << (index & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index += 1;

    return result;
}


Solution 3:

static inline unsigned int get_bits1_variant3(GetBitContext *s)
{
    unsigned int index = s->index;

#if defined BITSTREAM_READER_LE
    uint8_t result = ((s->buffer[index >> 3] >> (index & 7)) & 1);
#elif !defined BITSTREAM_READER_LE
    uint8_t result = ((s->buffer[index >> 3] << index % 8) >> (8 - 1));
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index++;
#endif

    return result;
}
