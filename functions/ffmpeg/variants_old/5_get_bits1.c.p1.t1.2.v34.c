Below is a variant of the function, which contains additional logical branch for BITSTREAM_READER_LE.


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];

#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    if (result & 1)
        result &= 1;
    else
        result >>= index & 7;
#else
    result <<= index & 7;
    result  = result >> (8 - 1);
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {
#endif
        index++;
    s->index = index;

    return result;
}
";
