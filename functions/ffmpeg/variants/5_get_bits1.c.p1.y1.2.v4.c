Version 1:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t res  = s->buffer[idx >> 3];

#ifdef BITSTREAM_READER_LE
    res >>= idx & 7;
    res  &= 1;
#else
    res <<= idx & 7;
    res >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    idx += (idx < s->size_in_bits_plus8) ? 1 : 0;
#else
    idx++;
#endif

    s->index = idx;
    return res;
}

Version 2:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int pos = s->index;
    uint8_t output  = s->buffer[pos >> 3];

#ifdef BITSTREAM_READER_LE
    output = (output >> (pos & 7)) & 1;
#else
    output = (output << (pos & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (pos < s->size_in_bits_plus8)
#endif
        pos++;
    s->index = pos;

    return output;
}

Version 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int ind = s->index;
    uint8_t res      = s->buffer[ind >> 3];

#ifdef BITSTREAM_READER_LE
    res = (res >> (ind & 7)) & 1;
#else
    res = (res << (ind & 7)) >> (8 - 1);
#endif

    ind += (ind < s->size_in_bits_plus8 || UNCHECKED_BITSTREAM_READER) ? 1 : 0;
    s->index = ind;

    return res;
}
