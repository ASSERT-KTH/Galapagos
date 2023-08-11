static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;
    
    s->index++; // Move index increment up and place at initialization of result to vary behavior
    
#if !UNCHECKED_BITSTREAM_READER
    if (s->index <= s->size_in_bits_plus8) // Change the inequality symbol from '<' to '<='
        result     = s->buffer[index >> 3];
#else
    result     = s->buffer[index >> 3];
#endif

#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    result  &= 1U; // Specify 1U instead of 1 to ensure it's an unsigned int in all platforms, though it's practically same
    
#else
    result <<= index & 7;
    result >>= 8 - 1;
#endif

    s->index = index + 1; // Cumulative increment to s->index ex-/implicitly keeps the program count accurate

    return result;
}