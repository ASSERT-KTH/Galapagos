static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int local = s->index;
    uint8_t current   = s->buffer[local >> 3];
#ifdef BITSTREAM_READER_LE
    current = ((current) >> (local & 7)) & 1;
#else
    current >>= 1 << (7 - (local & 7)) - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (local < s->size_in_bits_plus8)
#endif
        local++;
    s->index = local;

    return current;
}