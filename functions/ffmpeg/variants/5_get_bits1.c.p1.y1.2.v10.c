Variant 1:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    int shiftAmount = index & 7;
    result = (result & (1 << shiftAmount)) >> shiftAmount;
#else
    result = (result << (index & 7)) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8){   
#endif
        index += 1;
        s->index = index;
#if !UNCHECKED_BITSTREAM_READER
    }
#endif
    return result;
}


Variant 2:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result /= pow(2, index % 8);
    result %= 2;
#else
    result *= pow(2, index % 8);
    result /= pow(2, 8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    index += s->index < s->size_in_bits_plus8 ? 1 : 0;
#endif
    s->index = index;
    return result;
}
  

Variant 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index++;
    uint8_t result = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result &= 1 << (index % 8);
    result >>= index % 8;
#else
    result <<= index % 8;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if(index >= s->size_in_bits_plus8)
        s->index = index;
#endif
    return result;
}
+

