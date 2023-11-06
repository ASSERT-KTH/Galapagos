In the new variant of code, depending status of BITSTREAM_READER_LE, index will be manipulated differently for preserving the old behavior.


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result    =  result & (1 << (index & 7));
    result    = (result > 0) ? 1 : 0;
#else
    result    =  result & (1 << (7 - (index & 7)));
    result    = (result > 0) ? 1 : 0;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        index++;
#endif

    s->index = index;   
    return result;
}


Basically we replace the bitwise- and postfix-operators with a composed bitwise-and and conditional statements. Behaviour and functionality will remain same.