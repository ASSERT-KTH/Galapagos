static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    
    uint8_t result = s->buffer[index >> 3];
    
#ifdef BITSTREAM_READER_LE
    result >>= (index & 7);
    /* Changed from masking with 1 to masking with 0xFF to ensure same result when masking */
    result  &= 0xFF; 
#else
    result <<= (index & 7);
    result >>= (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    /* Explicitly checking if the index is less than 'size_in_bits_plus8' */
    if (s->index < (s->size_in_bits_plus8))
#endif
        index = index + 1; // Instead of '++' used '+1'
        
    s->index = index;

    return result;
}