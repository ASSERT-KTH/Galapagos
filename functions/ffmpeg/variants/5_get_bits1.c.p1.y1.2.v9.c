Variant 1 (Changing variable names):

static inline unsigned int get_bits1_variant1(GetBitContext *t)
{
    unsigned int idx = t->index;
    uint8_t res      = t->buffer[idx >> 3];
#ifdef BITSTREAM_READER_LE
    res >>= idx & 7;
    res  &= 1;
#else
    res <<= idx & 7;
    res >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (t->index < t->size_in_bits_plus8)
#endif
        idx++;
    t->index = idx;

    return res;
}


Variant 2 (Switching arithmetic order, Note: This is only feasible when the program does not rely on specific bit arithmetic order):

static inline unsigned int get_bits1_variant2(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result &= 1;
    result >>= index & 7;
#else
    result >>= 8 - 1;
    result <<= index & 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        index++;
    s->index = index;

    return result;
}

Variant 3 (An alternative approach using ternary operator over loops):

static inline unsigned int get_bits1_variant3(GetBitContext *s) 
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
    
#ifdef BITSTREAM_READER_LE
    result = (result >>= (index & 7)) & 1;
#else
    result = ((result <<= (index & 7)) >> (8 - 1));
#endif
#if !UNCHECKED_BITSTREAM_READER
    index += (s->index < s->size_in_bits_plus8) ? 1 : 0;
#else
    index++;
#endif
    s->index = index;

    return result;
}
