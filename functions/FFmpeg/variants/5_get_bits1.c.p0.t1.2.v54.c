static inline unsigned int get_bits1_alt(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;
#ifdef BITSTREAM_READER_LE
    result = s->buffer[index/8];
    result &= 1 << (index % 8);
    result = result != 0;
#else
    result = s->buffer[index/8];
    result >>= (index % 8);
    result <<= 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (++index << 3 < s->size_in_bits_plus8)
#endif
        s->index = index;

    return result;
}