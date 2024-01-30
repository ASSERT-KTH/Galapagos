Variant 1

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int actual_index = s->index;
    uint8_t resultant    = s->buffer[actual_index >> 3];
#ifdef BITSTREAM_READER_LE
    resultant >>= actual_index & 7;
    resultant &= 1;
#else
    resultant <<= actual_index & 7;
    resultant >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        actual_index = actual_index + 1;
    s->index = actual_index;

    return resultant;
}


Variant 2

static inline unsigned int get_bits1(GetBitContext *s)
{
    int index_val = s->index;
    uint8_t result_val     = s->buffer[index_val >> 3];
#ifdef BITSTREAM_READER_LE
    result_val >>= index_val & 7;
    result_val  &= 1;
#else
    result_val <<= index_val & 7;
    result_val >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        index_val += 1;
    s->index = index_val;

    return result_val;
}


Variant 3

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t resulting_val     = s->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    resulting_val >>= idx & 7;
    resulting_val  &= 1;
#else
    resulting_val <<= idx & 7;
    resulting_val >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        idx++;
    s->index = idx;

    return resulting_val;
}
