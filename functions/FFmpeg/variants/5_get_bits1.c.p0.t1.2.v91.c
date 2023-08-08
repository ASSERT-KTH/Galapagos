static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index;
    uint8_t result;

    index = s->index;
    result = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
    result /= pow(2, index % 8);
    result  %= 2;
#else
    result *= pow(2, index % 8);
    result /= pow(2, 8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {
        s->index++;
    }
    index = s->index;
#else
    index++;
    s->index = index;
#endif

    return result;
}