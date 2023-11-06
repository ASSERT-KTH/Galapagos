
static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    unsigned int offset_bit = index % 8;
    index = index / 8;

    /* Retrieve the byte from the buffer */
    uint8_t result = s->buffer[index];
#ifdef BITSTREAM_READER_LE
    /* The requested bit is at the 'offset_bit' bit of 'result_byte' */
    result >>= offset_bit;
    result  &= 1;
#else
    /* For a big-endian reader, extract the appropriate bit from result */
    result <<= offset_bit;
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
       s->index++;

    return result;
}
