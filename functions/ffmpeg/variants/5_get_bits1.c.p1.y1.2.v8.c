Variant 1:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int position = s->index;
    uint8_t outcome = s->buffer[position >> 3];
    
    if(BITSTREAM_READER_LE)
    {
    	outcome = outcome >> (position & 7);
    	outcome = outcome & 1;        
    }
    else
    {
    	outcome = outcome << (position & 7);
    	outcome = outcome >> (8 - 1);
    }

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        position++;
    
    s->index = position;

    return outcome;
}

Variant 2:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int idx = s->index;
    uint8_t ret = s->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    ret >>= idx & 7;
    ret  &= 1;
#else
    ret <<= idx & 7;
    ret >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        idx++;

    s->index = idx;

    return ret;
}
 

Variant 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int i = s->index;
    uint8_t r  = s->buffer[i >> 3];
#ifdef BITSTREAM_READER_LE
    r >>= i & 7;
    r  &= 1;
#else
    r <<= i & 7;
    r >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        i++;

    s->index = i;

    return r;
}
