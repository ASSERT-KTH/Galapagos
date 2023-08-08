static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;
    if (index >= 0 && index <= 7) {
        result = s->buffer[index];
#ifdef BITSTREAM_READER_LE
        result >>= index;
        result  &= 1;
#else
        result <<= index;
        result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
        if (s->index < s->size_in_bits_plus8)
#endif
            index += 1;
        s->index = index;
    } else {
        result = s->buffer[(index >> 3)];
    }

    return result;
}