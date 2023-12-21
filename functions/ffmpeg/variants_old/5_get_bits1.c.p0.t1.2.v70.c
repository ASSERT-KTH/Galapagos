static inline unsigned int get_bits_different(GetBitContext *structPtr)
{
    unsigned int var = structPtr->index;
    uint8_t val = structPtr->buffer[var >> 3];

#ifdef BITSTREAM_READER_LE
    val >>= (var & 7);
    val  &= 1;
#else
    val = (val << (var & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (structPtr->index < structPtr->size_in_bits_plus8)
#endif
        var++;
        
    structPtr->index = var;

    return val;
}