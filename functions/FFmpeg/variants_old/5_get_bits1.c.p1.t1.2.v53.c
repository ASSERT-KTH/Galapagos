static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8];
      
#ifdef BITSTREAM_READER_LE
    unsigned int index_mod_8 = index % 8;
    result >>= index_mod_8;  
    result &= 1;                
#else
    result <<= index % 8;      
    result >>= 8 - 1;
#endif
    
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8) 
        index++;
#endif
    
    s->index = index;

    return result;    
}