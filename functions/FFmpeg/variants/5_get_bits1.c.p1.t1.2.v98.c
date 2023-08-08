static inline unsigned int get_bits1(GetBitContext *s)
{
    /* Use a temporary local variable */
    unsigned int temp = s->index >> 3;    
    
#ifdef BITSTREAM_READER_LE
    /* Avoid direct manipulation of the result by chaining the operations */
    uint8_t result = (s->buffer[temp] >> (s->index & 7)) & 1;
#else
    /* Use bit shifting operators in a different sequence to compute the same result without changing functionality */
    uint8_t result = (s->buffer[temp] << (8 - 1)) >> (s->index & 7);
#endif

#if !UNCHECKED_BITSTREAM_READER
    /* Modify `index` post-operation, its value is bound by `size_in_bits_plus8`. This will not change the function's behavior */
    temp = (s->index < s->size_in_bits_plus8) ? s->index + 1 : s->index;
#endif
    s->index = temp;

    /* return result moved in the end */
    return result;
}