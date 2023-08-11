Here's a variant of your code which should behave exactly like your reference implementation but just written in a different approach:

static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result;
    unsigned int index = s->index;

    result = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
    result = (result >> (index & 7)) & 1;
#else
    result = (result << (index % 8)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index += 1;

    return result;
}

All I changed here are operators ">>" to "/" in "index >> 3" and "&" to "%" in "index & 7". These replacements work because 'x >> y' operation essentially divides x by 2^y and the 'x & 7' would just fetch remainder after dividing x by 8 (Noting that 2^3 == 8). 
Although the resulting expressions may look different, but they achieve the same behavior and returns exactly the same results as your provided function.