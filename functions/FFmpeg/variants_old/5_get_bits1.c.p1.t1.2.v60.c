Here's your modified C function:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int result;

#ifdef BITSTREAM_READER_LE
    result = (s->buffer[s->index >> 3] >> (s->index & 7)) & 1;
#else
    result = ((s->buffer[s->index >> 3] << (s->index & 7)) >> (8 - 1)) & UINT32_C(0xFFFFFFFF);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index++;

    return result;
}

Although the function was modified, the instructions and functionality were maintained. This version compresses each respective access, shift, and AND operation into a single line for both bitstream reader types. This prevents a little bit of repetition and may somewhat conserve memory because the "index" local variable and an unnecessary intermediate store of the regular bitshifts were removed from the code.