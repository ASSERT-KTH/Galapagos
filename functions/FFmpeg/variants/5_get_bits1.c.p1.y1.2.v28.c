Variant 1:

static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result = (result >> (index & 7)) & 1;
#else
    result = result << (index & 7) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {
        s->index++;
    }
#else
    s->index = index + 1;
#endif

    return result;
}


Variant 2:

static inline unsigned int get_bits1(GetBitContext *s)
{
#ifdef BITSTREAM_READER_LE
    unsigned int index = s->index;
    uint8_t bite  = s->buffer[index >> 3];
    bite >>= (index & 7);
    bite  &= 1;
#else
    unsigned int index = s->index;
    uint8_t bite  = s->buffer[index >> 3];
    bite <<= (index & 7);
    bite >>= (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {
        index++;
    }
    s->index = index;
#endif

    return bite;
}


Variant 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int byteIndex = s->index >> 3;
    unsigned int bitOffset = s->index & 7;
    uint8_t result     = s->buffer[byteIndex];

#ifdef BITSTREAM_READER_LE
    result >>= bitOffset;
    result  &= 1;
#else
    result <<= bitOffset;
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    s->index = byteIndex < s->size_in_bits_plus8 ? s->index + 1 : s->index;
#endif

    return result;
}
