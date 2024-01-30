1.
static inline unsigned int get_bits2(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t res      = s->buffer[idx / 8];
#ifdef BITSTREAM_READER_LE
    res >>= idx % 8;
    res  &= 1;
#else
    res <<= idx % 8;
    res >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        idx++;
    s->index = idx;

    return res;
}

2.
static inline unsigned int get_bits3(GetBitContext *s)
{
    unsigned int tmp_index = s->index;
    uint8_t tmp_result     = s->buffer[tmp_index / 8];
#ifdef BITSTREAM_READER_LE
    tmp_result >>= tmp_index % 8;
    tmp_result  &= 1;
#else
    tmp_result <<= tmp_index % 8;
    tmp_result >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (tmp_index < s->size_in_bits_plus8)
#endif
        ++tmp_index;
    s->index = tmp_index;

    return tmp_result;
}

3.
static inline unsigned int get_bits4(GetBitContext *s)
{
    unsigned int indx = s->index;
    uint8_t rslt     = s->buffer[indx >> 3];
#ifdef BITSTREAM_READER_LE
    rslt >>= indx & 7;
    rslt  &= 1;
#else
    rslt <<= indx & 7;
    rslt >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (indx < s->size_in_bits_plus8)
#endif
        indx++;
    s->index = indx;

    return rslt;
}