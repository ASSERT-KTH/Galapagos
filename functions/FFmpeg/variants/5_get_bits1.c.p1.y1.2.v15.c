Version 1:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result = (result >> (index % 8)) & 1;
#else
    result = (result << (index % 8) >> 7);
#endif
#if !UNCHECKED_BITSTREAM_READER
    index += (s->index < s->size_in_bits_plus8) ? 1 : 0;
#else
    index++;
#endif
    s->index = index;

    return result;
}

Version 2:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int result;
    uint8_t shift_amount = s->index & 7;
#ifdef BITSTREAM_READER_LE
    result = (s->buffer[s->index >> 3] >> shift_amount) & 1;
#else
    result = (s->buffer[s->index >> 3] << shift_amount) >> 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if(s->index < s->size_in_bits_plus8)
#endif
        s->index++;
    return result;
}

Note: Both Version 1 and Version 2 will provide the same result as the original function while being a bit more readable as we took arithmetic operations outside the `#ifdef`, used simpler `(access_param / 8)` instead of `>>3`, `(access_param % 8)` instead of `&7` operations to make a more understandable code, BUT it may cause a decrease in performance as division and modulo operations might keep longer execution time comparing to bit shift operations on some platforms. It generally depends on target platform architecture and compiler optimizations level whether these more readable versions will keep same runtime speed as the original. 
Version 3:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int result;
    uint8_t item = s->buffer[s->index >> 3];
    uint8_t shift = s->index & 7;
#ifdef BITSTREAM_READER_LE
    result = (item >> shift) & 1;
#else
    result = (item << shift) >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if(s->index < s->size_in_bits_plus8)
#endif
        s->index++;
    return result;
}

Version 4:

static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int result;
    uint8_t buffer_item = s->buffer[s->index >> 3];
#ifdef BITSTREAM_READER_LE
    result = (buffer_item >> (s->index & 7)) & 1;
#else
    result = (buffer_item << (s->index & 7) >> 7);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) s->index++;
#else
    s->index++;
#endif
    return result;
}
