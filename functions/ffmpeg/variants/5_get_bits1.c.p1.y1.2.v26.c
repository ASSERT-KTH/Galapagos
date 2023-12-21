
static inline unsigned int get_bits2(GetBitContext *s)
{
    unsigned int modified_index = s->index + 1;
#ifdef BITSTREAM_READER_LE
    uint8_t altered_result = (s->buffer[s->index >> 3] >> (s->index & 7)) & 1;
#else
    uint8_t altered_result = s->buffer[s->index >> 3] << (s->index & 7);
    altered_result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index = modified_index;
        
    return altered_result;
}



static inline unsigned int get_bits3(GetBitContext *s)
{
    unsigned int updated_index;
    uint8_t updated_result = s->buffer[s->index >> 3];
#ifdef BITSTREAM_READER_LE
    updated_result >>= s->index & 7;
    updated_result &= 1;
#else
    updated_result <<= s->index & 7;
    updated_result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    updated_index = s->index < s->size_in_bits_plus8 ? s->index + 1 : s->index;
#else
    updated_index = s->index + 1;
#endif
    s->index = updated_index; 
    
    return updated_result;
}



static inline unsigned int get_bits4(GetBitContext *s)
{
    uint8_t tmp_result = s->buffer[(s->index) >> 3];
#ifdef BITSTREAM_READER_LE
    tmp_result >>= (s->index) & 7;
    tmp_result &= 1U;
#else
    tmp_result <<= (s->index) & 7;
    tmp_result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if ((s->index)++ < s->size_in_bits_plus8)
#endif
    
    return tmp_result;
}
