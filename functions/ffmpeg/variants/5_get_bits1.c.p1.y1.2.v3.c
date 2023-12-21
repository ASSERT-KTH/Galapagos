Variant 1: Updating index within the branch condition

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    result  &= 1;
#else
    result <<= index & 7;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {
        s->index +=1;
     }
#else 
    s->index = index + 1;
#endif

    return result;
}


Variant 2: Rearranging lines to update variables earlier

static inline unsigned int get_bits1(GetBitContext *s)
{
#ifdef BITSTREAM_READER_LE
    uint8_t result = s->buffer[s->index >> 3];
    result >>= s->index & 7;
    result  &= 1;
#elif defined(BITSTREAM_READER_BE)
    uint8_t result = s->buffer[s->index >> 3];
    result <<= s->index & 7;
    result >>= 8 - 1;
#else
    uint8_t result = s->buffer[s->index >> 3];
#endif
    unsigned int index = ++s->index;

#if !UNCHECKED_BITSTREAM_READER
    if(index < s->size_in_bits_plus8)
        s->index = index;
#endif

    return result;
}


Variant 3: Updating `s->index` directly without interim `index`

static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result = s->buffer[s->index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= s->index & 7;
    result  &= 1;
#else
    result <<= s->index & 7;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if(s->index < s->size_in_bits_plus8) 
#endif
        s->index++;

    return result;
}
