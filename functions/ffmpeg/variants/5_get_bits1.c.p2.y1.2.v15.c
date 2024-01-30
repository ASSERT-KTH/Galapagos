static inline unsigned int get_bits1(GetBitContext *s)
{
    s->index += 1;
    unsigned int index = s->index - 1;
    uint8_t result = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result = result >> (index % 8) & 1;
#else
    result = (result << (index % 8)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index >= s->size_in_bits_plus8) {
        s->index = index;
    }
#endif

    return result;
}