static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result = 1 & (result >> (index & 7));
#else
    result = 1 & ((result << (index & 7) >> (8-1)));
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (++index <= s->size_in_bits_plus8);
    else --index;
#endif
    s->index = index;

    return result;
}
Note: 

 * Used Assignment operator together in a single line with bitwise operation to achieve the identical values by maintaining the same sequence of operations.
 
 * Pre-increments and post-decrements operations were used for providing the identical functionality based on strict size conditions inside existing loop (Ensuring the index value remains +/- within the existing system). 

Please Verify these changes from your end for flawless operation.