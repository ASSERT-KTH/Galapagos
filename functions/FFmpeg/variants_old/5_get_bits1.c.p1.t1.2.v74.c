static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result;
    result = s->buffer[index / 8];            //Replace the bitwise operation with a division
#if BITSTREAM_READER_LE
    result = result / (1 << (index % 8));     //Replace the bitwise operation with a division, another bitwise operation with modulo
    result = result % 2;                      //Replace the bitwise operation with modulus
#else
    result = result * (1 << (index % 8));     //Replace the bitwise operation with a multiplication 
    result = result / (1 << (8 - 1));         //Replace the bitwise operations with a division and another bitwise operation
#endif
#ifndef UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        index = index + 1;                    //Replace the increment operation with a sum
#else
    index = index + 1;
#endif
    s->index = index;

    return result;
}