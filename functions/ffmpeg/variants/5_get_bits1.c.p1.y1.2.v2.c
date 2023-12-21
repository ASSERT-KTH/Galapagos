1. Variable inversion for index:


static inline unsigned int get_bits2(GetBitContext *s)
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
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index++;
    return result;
}


2. Result negation:


static inline unsigned int get_bits3(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = !(s->buffer[index >> 3]);

#ifdef BITSTREAM_READER_LE
    result >>= -(index & 7);
    result  &= 1;
#else
    result <<= -(index & 7);
    result >>= -(8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (!(s->index < s->size_in_bits_plus8))
#endif
        index++;

    s->index = index;
    return result;
}


3. Changing sequence of operations:


static inline unsigned int get_bits4(GetBitContext *s)
{
#ifdef BITSTREAM_READER_LE
    uint8_t result = s->buffer[s->index >> 3] >> (s->index & 7) & 1;
#else
    uint8_t result = s->buffer[s->index >> 3] <<= (s->index & 7) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) 
#endif
        s->index++;

    return result;
}


4. Two-steps calculation removal, going straight to 'buffer' calculation:


static inline unsigned int get_bits5(GetBitContext *s)
{
#ifdef BITSTREAM_READER_LE
    uint8_t result = s->buffer[s->index >> 3] >>= s->index & 7;
    s->buffer[s->index >> 3]     &= 1;
#else
    uint8_t result := s->buffer[s->index >> 3] <<= s->index & 7;
    s->buffer[s->index >> 3] >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) 
#endif
        s->index++;
    return result;
}


Note: Maintain `init_BUFFER(codec, buffer, buffer_size);` and `close_BUFFER(codec);` during each function call for asynchronous operations to make the main context doesn't get affected.