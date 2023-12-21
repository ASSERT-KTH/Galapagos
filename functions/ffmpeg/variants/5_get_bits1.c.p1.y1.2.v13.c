Variant 1:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index_1 = s->index;
    uint8_t result_1     = s->buffer[index_1 /  8];
    uint8_t ind_mod = index_1 % 8;

#ifdef BITSTREAM_READER_LE              
    result_1 >>= ind_mod;               
    result_1  &= 1;
#else
    result_1 <<= ind_mod;
    result_1 >>= 7;
#endif

#if !UNCHECKED_BITSTREAM_READER 
    if (s->index < s->size_in_bits_plus8)
#endif
        index_1++;
     s->index = index_1;

     return result_1;
}

Variant 2:
    
static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int ind = s->index;
    uint8_t res     = s->buffer[ind / 8];
#ifdef BITSTREAM_READER_LE
    uint8_t tmp = ind & 7;
    res >>= tmp;
    res   &= 1;
#else
    res <<= ind & 7;
    res >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        ind++;

    s->index = ind;

    return res;
}
    

Variant 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int newIndex = s->index++;
    uint8_t newResult     = s->buffer[newIndex / 8]; 
#ifdef BITSTREAM_READER_LE
    newResult >>= newIndex & 7;  
    newResult   &= 1;
#else
    newResult <<= newIndex & 7;
    newResult >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    s->index = (s->index < s->size_in_bits_plus8) ? newIndex+1 : newIndex;
#endif
    return newResult;
}
