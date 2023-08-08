static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;
    if (s->buffer != NULL) {
        result = s->buffer[index/8];
    }
#ifdef BITSTREAM_READER_LE
    result >>= index % 8;
    result  = result & 1;
#else
    result <<= index % 8;
    result = result >> ((8 - 1)%8);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index+1 <= s->size_in_bits_plus8)
#endif
        index++;
    s->index = index;

    return result;
}