Here's a variant that adds some intermediate assignments for better readability:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];
    unsigned int shift_amount = index & 7;

#ifdef BITSTREAM_READER_LE
    result >>= shift_amount;
    result &= 1;
#else
    result <<= shift_amount;
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        index += 1;
#else
    index += 1;
#endif

    s->index = index;
    return result;
}


Here's another variant that reorders some of the logical statements for potential execution optimizations:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    
#ifdef BITSTREAM_READER_LE
    uint8_t result = s->buffer[index >> 3];
    result >>= (index & 7);
    result &= 1;
#else
    uint8_t result = s->buffer[index >> 3];
    result <<= (index & 7);
    result >>= (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
        index++;
#else
    index++;
#endif

    s->index = index;
    return result;
}


And the third variant using a tertiary operator: 


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result = (result >>= (index & 7)) & 1;
#else
    result = (result <<= (index & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    index = (index < s->size_in_bits_plus8) ? index++ : index;
#else
    index++;
#endif

    s->index = index;

    return result;
}
