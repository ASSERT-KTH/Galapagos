
static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s-> index;
    uint8_t result     = 0;
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8) {
#endif
#ifdef BITSTREAM_READER_LE
        result = s->buffer[index >> 3] >> (index & 7);
        result &= 1;
    #else
        result = (s->buffer[index >> 3] << (index & 7)) >> (8 - 1);
    #endif
        s->index = ++index;
#if !UNCHECKED_BITSTREAM_READER
    }
#endif

    return result;
}
