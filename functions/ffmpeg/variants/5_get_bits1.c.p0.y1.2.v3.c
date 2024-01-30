static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index;
    uint8_t result;

    index = s->index;
    result = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
   result = 1 & (result >> (index % 8));
#else
   result = (1 << (7 - (index % 8))) & result;
   result = result >> (7 - (index % 8));
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {
        index++;
    }
#endif

    s->index = index;

    return result;
}
