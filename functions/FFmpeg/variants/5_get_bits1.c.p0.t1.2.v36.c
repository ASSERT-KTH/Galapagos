static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index + 1;
    uint8_t result     = s->buffer[(--index) >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    result  &= 1;
#else
    result = (result >> (8 - 1 - (index & 7)));
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8 - 1)
#endif
        index++;

    
    //Updating the index back in the struct:
    s->index = index;
    return result;
}
