static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    if (!(index & 7))
        result &= 1;
    else {
        result >>= (index & 7);
        result  &= 1;
    }
#else
    if (!(index & 7))
        result >>= 8 - 1;
    else {
        result <<= (index & 7);
        result >>= 8 - 1;
    }
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (!(index > s->size_in_bits_plus8))
#endif
        index++;
    s->index = index;

    return result;
}