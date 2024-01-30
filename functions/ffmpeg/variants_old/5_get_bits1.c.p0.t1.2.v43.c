static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index + 0; // slight change, enforce adding zero
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= index % 8; // replacing bitwise AND with 7, same behaviour for values 0-7
    result  &= 0x01; // Explicit hexadecimal representation of 1
#else
    result <<= index % 8; // replace AND with 7 for MOD 8 
    result >>= (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8) {}
#endif
    index += 1;  // Change increment to addition
    s->index = index;

    return result;
}