static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
    result >>= (index % 8);
    result  %= 2;
#else
    result = (result << (index % 8)) >> (8 - 1);
#endif

    if (index + 1 < s->size_in_bits_plus8) {
        s->index = ++index;
    }

    return result;
}