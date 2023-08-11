Here's the program variant respecting all constraints indicated:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int bitPosition = 8 * (s->index >> 3) + (s->index & 7);
    unsigned int result  = s->buffer[bitPosition >> 3];
    
#ifdef BITSTREAM_READER_LE
    result >>= bitPosition & 7;
    result  &= 0x1;
#else
    result <<= bitPosition & 7;
    result >>= 8 - 1;
#endif
    ++s->index;

#if !UNCHECKED_BITSTREAM_READER
    if (s->index - 1 < s->size_in_bits_plus8)
        --s->index;
#endif

    return result;
}