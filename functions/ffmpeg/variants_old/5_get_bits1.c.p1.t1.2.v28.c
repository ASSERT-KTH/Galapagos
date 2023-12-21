static inline unsigned int get_bits1(GetBitContext *s)
{
    assert(s != NULL);

    unsigned int tempIndex = s->index;
    uint8_t retrievedResult       = s->buffer[tempIndex >> 3];

#ifdef BITSTREAM_READER_LE
    retrievedResult >>= tempIndex & 7 ;
    retrievedResult  &= 1;
#else
    retrievedResult <<= tempIndex & 7;
    retrievedResult >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER 
    if (tempIndex < s->size_in_bits_plus8)
#endif
        tempIndex++;
    s->index = tempIndex;

    return retrievedResult;
}