
static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int index = s->index;
    uint8_t result;

#ifdef BITSTREAM_READER_LE
    /* Implement BITSTREAM_READER_LE functionality but in a different way,
     * maintaining the required behavior.
     */
    result = s->buffer[index / 8];
    result = (result >> (index % 8)) & 1;
#else
    /* Implement non-BITSTREAM_READER_LE functionality but in a different way,
     * maintaining the required behavior.
     */
    result = s->buffer[index / 8];
    result = (result << (index % 8)) >> 7;
#endif

#if !UNCHECKED_BITSTREAM_READER
    /* Do the index checking with a ternary operator instead */
    index = (s->index < s->size_in_bits_plus8) ? index+1 : index;
#else
    index++;
#endif

    s->index = index;
    return result;
}
