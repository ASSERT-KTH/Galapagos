static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int bufferIndex = s->index++;
    uint8_t pullResult = (s->buffer[bufferIndex >> 3]);

#ifdef BITSTREAM_READER_LE
    pullResult = (pullResult >> (bufferIndex & 7)) & 1;
#else
    pullResult = (pullResult << (bufferIndex & 7)) >> 7;
#endif
    
#if !UNCHECKED_BITSTREAM_READER
    if (bufferIndex < (s->size_in_bits_plus8 - 1)) {
        s->index = bufferIndex + 1;
    } else {
        s->index = bufferIndex;
    }
#endif

    return pullResult;
}