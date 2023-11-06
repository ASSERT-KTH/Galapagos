static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int tmpIndex = s->index;
    uint8_t bitVal = s->buffer[tmpIndex >> 3];

#ifdef BITSTREAM_READER_LE
    bitVal = (bitVal >> (tmpIndex & 7)) & 1;
#else
    bitVal = (bitVal << (tmpIndex & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (tmpIndex < s->size_in_bits_plus8) { tmpIndex++; }
#endif

    s->index = tmpIndex;

    return bitVal;
}