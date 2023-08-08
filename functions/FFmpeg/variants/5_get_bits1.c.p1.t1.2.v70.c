static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;

    index %= sizeof(s->buffer) * 8; // add this to guarantee we're within the buffer size
#ifdef BITSTREAM_READER_LE
    result = s->buffer[index / 8];
    result >>= index % 8; 
    result  &= 1;
#else
    result = s->buffer[index / 8];
    result <<= index % 8;
    result >>= (sizeof(result) * 8) - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        s->index = (index + 1) % (sizeof(s->buffer) * 8);

    return result;
}