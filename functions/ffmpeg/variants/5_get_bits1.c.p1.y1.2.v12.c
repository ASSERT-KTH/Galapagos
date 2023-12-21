Variant 1:

static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned int idx    = s->index;
    uint8_t final_result = s->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    final_result = (final_result >> (idx & 7)) & 1;
#else
    final_result = (final_result << (idx & 7)) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
    s->index = ++idx;

    return final_result;
}


Variant 2:

static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned int ref_index    = s->index;
    uint8_t calc_result = s->buffer[ref_index >> 3];
#ifdef BITSTREAM_READER_LE
    calc_result >>= ref_index & 7;
    calc_result   &= 1;
#else
    calc_result <<= ref_index & 7;
    calc_result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (ref_index < s->size_in_bits_plus8)
#endif
        ref_index++;
    s->index = ref_index;

    return calc_result;
}

   
Variant 3:

static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned int ref    = s->index;
    uint8_t bitsRepresentation = s->buffer[ref >> 3];
#ifdef BITSTREAM_READER_LE
    bitsRepresentation = bitsRepresentation >> (ref & 7);
    bitsRepresentation  = bitsRepresentation & 1;
#else
    bitsRepresentation = bitsRepresentation << (ref & 7);
    bitsRepresentation = bitsRepresentation >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (ref < s->size_in_bits_plus8)
#endif      
    ref++;
    s->index = ref;
    return bitsRepresentation;
}
