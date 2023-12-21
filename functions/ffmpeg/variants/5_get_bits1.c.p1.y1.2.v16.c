1. Using compound assignments

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= (index & 7);
    result &= 1;
#else
    result <<= (index & 7);
    result >>= (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        index++;
#endif
    s->index = index;

    return result;
}

   
2. Using ternary operator

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= (index & 7);
    result &= 1;
#else
    result <<= (index & 7);
    result >>= (8 - 1);
#endif

#ifndef UNCHECKED_BITSTREAM_READER
    s->index = (s->index < s->size_in_bits_plus8) ? ++index : index;
#else
    s->index = ++index;
#endif

    return result;
}

    
3. Swaping sequence of statement execution

    
static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result = s->buffer[s->index >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= (s->index & 7);
    result &= 1;
#else
    result <<= (s->index & 7);
    result >>= (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index++;
#endif

    return result;
}
