Version 1:

static inline unsigned int get_bits2(GetBitContext *s) 
{
    unsigned int idx = s->index;
    uint8_t res      = s->buffer[idx / 8];

#ifdef BITSTREAM_READER_LE
    res >>= idx % 8;
    res  &= 0x01;
#else
    res <<= idx % 8;
    res >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        idx++;
    s->index = idx;
    return res;
}

Version 2:

static inline unsigned int get_bits3(GetBitContext *s) 
{
    unsigned int temp = s->index;
    uint8_t value     = s->buffer[temp / 8];

#ifdef BITSTREAM_READER_LE
    value >>= temp & 0x07;
    value  &= 1;
#else
    value <<= temp & 0x07;
    value >>= 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        temp++;
    s->index = temp;
    return value;
}

Version 3:

static inline unsigned int get_bits4(GetBitContext* s)
{
   uint8_t val = s->buffer[s->index >> 3];
	
#ifdef BITSTREAM_READER_LE
   val >>= (s->index & 7);
   val &= 1;
#else
	val <<= (s->index & 7);
	val >>= 7;
#endif
	
#if !UNCHECKED_BITSTREAM_READER
   if (s->index < s->size_in_bits_plus8)
#endif
	   ++s->index;

   return val;
}