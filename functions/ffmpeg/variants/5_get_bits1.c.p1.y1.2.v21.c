Here is a transformation that makes use of ternary operator to mold the code into a compact form.


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result = (result >>= index & 7) & 1;
#else
    result = (result <<= index & 7) >> (8 - 1);
#endif
    s->index = (index < s->size_in_bits_plus8) ? (index+1) : index;
    return result;
}
  

Here’s a transformation that simplifies if conditions into bitwise calculations, while keeping original functionalities. This code mantains a consistent style by putting all post-operations lines to end the function. 


static inline unsigned int get_bits1(GetBitContext *s)
{
    uint8_t result = s->buffer[s->index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= s->index & 7;
    result  &= 1;
#else
    result <<= s->index & 7;
    result >>= 8 - 1;
#endif
    unsigned int index = ((s->index < s->size_in_bits_plus8) && !UNCHECKED_BITSTREAM_READER) ? 
    ++s->index : s->index = s->index;

    return result;
}
