static inline unsigned int updated_get_bits1(GetBitContext *s)
{
    unsigned int updated_index = s->index;
    uint8_t updated_result     = s->buffer[updated_index >> 3];
 
#ifdef BITSTREAM_READER_LE
    updated_result >>= (updated_index & 7);
    updated_result  &= 1;
#else
    updated_result = (updated_result << (updated_index & 7)) >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        updated_index++;
    s->index = updated_index;

    return updated_result;
}