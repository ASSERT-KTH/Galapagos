static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int stored_index;
    uint8_t result;

    stored_index = s->index;
    result = s->buffer[stored_index >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= (stored_index & 7);
    result &= 1;
#else
    result >>= 7 - (stored_index & 0x7);
    result <<= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (stored_index < s->size_in_bits_plus8)
#endif
    stored_index++;

    s->index = stored_index;

    return (unsigned int)result;
}