Sure, the conditional code makes the task quite engaging. I kept that functionality but restructured it a bit using another method and formatted it differently. The following should be a functionally equivalent variant using the divide/modulo operations instead of shifting to isolate the required bit:


static inline unsigned int get_bits1_variant(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8];

#ifdef BITSTREAM_READER_LE
    result /= (1 << (index % 8));
    result %= 2;
#else
    result *= (1 << (index % 8));
    result %= 256;
    result /= 128;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        index++;
    s->index = index;

    return result;
}


Just for understanding, division by 2^n effectively does a right-shift by n bits and modulo by 2^n effectively masks off all but the least n bits. Multiplication by 2^n effectively does a left-shift by n bits.