static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = 0; 
    if (index / 8 < sizeof(s->buffer)) // adding bounds check
    {
        result = s->buffer[index >> 3];
    }
#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    result  &= 0xFF; // ensuring it stays within a byte
#else
    result <<= index & 7;
    result >>= 7;
    result  &= 0xFF;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        index = index + 1;

    s->index = index;

    return result;
}