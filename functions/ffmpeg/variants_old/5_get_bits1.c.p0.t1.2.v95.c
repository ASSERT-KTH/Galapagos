static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8]; //Changed bit shifting with the equivalent arithmetic operation
    unsigned int mod_index = index % 8;
#ifdef BITSTREAM_READER_LE
    result >>= mod_index; //Reused equivalent mod operation instead ampersand with 7
    result  &= 1;
#else
    result <<= mod_index;
    result  = result >> 7; //Substituted subtracting 1 from 8 with just fixed number
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index++; //Increment operation moved directly inside if conditional
#endif
    else
    {
        index++;
        s->index = index;
    }

    return (unsigned int) result;
}
