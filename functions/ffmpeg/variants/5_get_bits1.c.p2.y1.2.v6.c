static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int ind = s->index;
    uint8_t res = s->buffer[ind / 8];

#ifdef BITSTREAM_READER_LE
    {
        unsigned int temp = ind % 8;
        res >>= temp;
        res &= 1;
    }
#else
    {
        unsigned temp = ind % 8;
        res <<= temp;
        res >>=(8 - 1);
    }
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (ind < s->size_in_bits_plus8)
        s->index = ind + 1;
#else
    s->index = ++ind;
#endif

    return res;
}