Variant 1:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifndef BITSTREAM_READER_LE
    result <<= index & 7;
    result >>= 8 - 1;
#else
    result >>= index & 7;
    result  &= 1;
#endif

#if defined(UNCHECKED_BITSTREAM_READER) && !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
    {
        index++;
    }
    s->index = index;

    return result;
    }


Variant 2:

static inline unsigned int get_bits1(GetBitContext *s)
{
    s->index++;
    unsigned int index = s->index - 1;
    uint8_t result = s->buffer[(index) >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    result  &= 1;
#else
    result <<= index & 7;
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8)
    {
        s->index = index;
    }
#endif
    return result;
    }


Variant 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result     = s->buffer[s->index >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= s->index & 7;
    result  &= 1;
#else
    result <<= s->index & 7;
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index++;
 
    return result;
    }
