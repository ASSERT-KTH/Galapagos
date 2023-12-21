static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int new_index = s->index; 
    uint8_t res = s->buffer[new_index >> 3];
#ifdef BITSTREAM_READER_LE
    new_index = new_index & 7;
    res >>= new_index;
    res  &= 1;
#else
    new_index = new_index & 7;
    res <<= new_index;
    res >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        new_index++;
    s->index = new_index;

    return res;
}