static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned long index = (unsigned long)s->index;
    uint8_t result      = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= (index & 7);
    result  &= 0x1;
#else
    uint8_t shift_value = index & 7;
    result <<= shift_value;
    result >>= (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) 
        s->index += 1;
#else
    s->index += 1;
#endif

    return (unsigned int)result;
}