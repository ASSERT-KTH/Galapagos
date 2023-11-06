static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int index_val = s->index;
    uint8_t result_val    = s->buffer[index_val >> 3];
#ifdef BITSTREAM_READER_LE
    result_val >>= (index_val % 8);
    result_val  &= 1;
#else
    result_val <<= index_val & 7;
    result_val >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        ++index_val;
    s->index = index_val;

    return result_val;
}