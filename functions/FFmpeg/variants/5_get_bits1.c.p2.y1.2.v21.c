static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index;
    uint8_t result;

    index = s->index;
    result = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
    result = (result >> (index % 8)) & 1;
#else
    result = (result << (index % 8)) >> (8 - 1);
#endif

    if (s->index < s->size_in_bits_plus8) {
        index += 1;
    }

    s->index = index;

    return result;
}