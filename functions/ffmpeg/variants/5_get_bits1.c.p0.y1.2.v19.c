static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int result;

#ifdef BITSTREAM_READER_LE
    result = !!(s->buffer[s->index >> 3] & (1 << (s->index & 7)));
#else
    result = (s->buffer[s->index >> 3] << (s->index & 7)) >> 7;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index++;

    return result;
}