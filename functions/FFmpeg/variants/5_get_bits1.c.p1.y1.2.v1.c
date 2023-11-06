Variant 1:

static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result;
#if defined(BITSTREAM_READER_LE)
    result = (s->buffer[s->index >> 3] >> (s->index & 7)) & 1;
#elif defined(UNCHECKED_BITSTREAM_READER)
    result = (s->buffer[s->index >> 3] << (s->index & 7)) >> 7;
#else
    s->index < s->size_in_bits_plus8 && (result = (s->buffer[s->index >> 3] << (s->index & 7)) >> 7);
#endif
    s->index++;

    return result;
}


Variant 2:

static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result;

    if (s->index < s->size_in_bits_plus8 || UNCHECKED_BITSTREAM_READER)
    {
#ifdef BITSTREAM_READER_LE
        result = (s->buffer[s->index >> 3] >> (s->index & 7)) & 1;
#else
        result = (s->buffer[s->index >> 3] << (s->index & 7)) >> 7;
#endif
        ++s->index;
    }

    return result;
}


Variant 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result;

#ifdef BITSTREAM_READER_LE
    result = (s->buffer[s->index >> 3] >> (s->index & 7)) & 1;
    if (s->index < s->size_in_bits_plus8 || UNCHECKED_BITSTREAM_READER)
#else
    result = (s->buffer[s->index >> 3] << (s->index & 7)) >> 7;
    if (s->index < s->size_in_bits_plus8)
#endif
    {
         ++s->index;
    }

    return result;
}


Variant 4:

static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result;

#ifdef BITSTREAM_READER_LE
    result = (s->buffer[s->index >> 3] >> (s->index & 7)) & 1;
#else
    result = (s->buffer[s->index >> 3] << (s->index & 7)) >> 7;
    if (s->index < s->size_in_bits_plus8)
#endif
    {
        ++s->index;
    }

    return result;
}
