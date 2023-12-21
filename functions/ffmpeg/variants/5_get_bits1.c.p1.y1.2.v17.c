Variant 1: Grouping Common Statements

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
    unsigned int bitPosition = index & 7;

#ifdef BITSTREAM_READER_LE
    result  = (result >> bitPosition) & 1;
#else
    result  = (result << bitPosition) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index++;
    else
        s->index = index;
#else
    s->index++;
#endif      
    return result;
}


Variant 2: Using Promotion of Course Grain Dealing With 'index'.

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int bitPosition;
    uint8_t result;

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index++;
#endif

    bitPosition = s->index & 7;
    result = s->buffer[s->index >> 3];

#ifdef BITSTREAM_READER_LE
    result = (result >> bitPosition) & 1;
#else
    result = (result << bitPosition) >> (8 - 1);
#endif

    return result;
}


Variant 3: Inverting #if Statement's Condition

   static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result  = (result >> (index & 7)) & 1;
#else
    result  = (result << (index & 7)) >> (8 - 1);
#endif

#ifdef UNCHECKED_BITSTREAM_READER
    s->index = index + 1;
#else
    if (s->index < s->size_in_bits_plus8)
        s->index = index + 1;
#endif

    return result;
}
