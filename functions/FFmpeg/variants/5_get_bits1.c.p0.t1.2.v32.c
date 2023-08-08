static inline unsigned int get_bits1_modified(GetBitContext *s)
{
    unsigned int position = s->index;
    uint8_t response      = s->buffer[position / 8];
#ifdef BITSTREAM_READER_LE
    response >>= position % 8;
    response  &= 0x1;
#else
    response <<= position % 8;
    response >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < (s->size_in_bits_plus8))
#endif
        position += 1;
    s->index = position;

    return response;
}