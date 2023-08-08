static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index       = s->index;
    uint8_t digit_bit_offset = index & 7;
    uint8_t result           = s->buffer[index >> 3]; 

#ifdef BITSTREAM_READER_LE
    result = (result >> digit_bit_offset) & 1;
#else
    result = (result << digit_bit_offset) >> (8 - 1);
#endif

    s->index = index + (8 >> (index < s->size_in_bits_plus8));
    
    return result;
}