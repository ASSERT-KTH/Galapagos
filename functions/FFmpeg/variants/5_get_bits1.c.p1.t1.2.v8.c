Here's a refactored version of your code. Same functionality, different approach.


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;

#ifdef BITSTREAM_READER_LE
    uint8_t result = s->buffer[index >> 3] >> (index & 7) & 1;
#else
    uint8_t result = s->buffer[index >> 3] << (index & 7) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if(index < s->size_in_bits_plus8)
#endif
        s->index = ++index;

    return result;
}


Please remember to replace the conditions of precompiling directives accordingly while you compile, as per requirement in your circumstances. 

(I wasn't clear if preprocessor directives could be modified within the answer, thus, I've left them as is.)  The refactoring merges two operands of the same variable into one and also position of incrementing `index` prior to assign it to `s->index`.