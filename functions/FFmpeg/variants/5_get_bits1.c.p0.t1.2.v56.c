static inline unsigned int get_bits1_v2(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result>>= index % 8;
    result = 0xFF & result;
#else
    result <<= (index % 8);
    result >>= (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    //using ternary operators instead of an IF statement
    index = (s->index < (s->size_in_bits_plus8)) ? ++index : index;
#else
    index++;
#endif
    s->index = ++index;
    //making sure the result is not greater than the range of unsigned int.
    return (result & 0xFFFFFFFF);
}