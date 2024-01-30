Here is a substitute implementation of the function:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int pos = s->index;
    uint8_t val      = s->buffer[pos >> 3];
#ifdef BITSTREAM_READER_LE
    val = (val >> (pos & 7)) & 1;
#else
    val = (val << (pos & 7)) >> 7;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (pos < s->size_in_bits_plus8)
#endif
        s->index = pos + 1;
    return val;
}


This substitute version follows all the same steps as the original function but rearranges the order of some operations for a slightly 'different' implementation. The essence of the task and its outcomes remain the same.