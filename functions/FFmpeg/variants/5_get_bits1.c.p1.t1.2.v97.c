Here's a variant of the function maintaining similar behavior and functionality:


static inline unsigned int get_bits1_alternative(GetBitContext *s)
{
    unsigned int shiftBits;
    unsigned int bitMask;
    uint8_t result;
    unsigned int oldIndex = s->index;
    s->index++;
#ifdef BITSTREAM_READER_LE
    shiftBits = oldIndex & 7;
    bitMask = 1;
#else
    shiftBits = 8 - 1;
    bitMask = oldIndex & 7;
#endif
    result = s->buffer[oldIndex >> 3];
    result = ((result >> bitMask) << shiftBits) >> bitMask;

#if !UNCHECKED_BITSTREAM_READER
    if (oldIndex >= s->size_in_bits_plus8)
        s->index = oldIndex;
#endif
    return result;
}

Functionality of new function is identical to initial one, but shift and bit mask operations are ordered differently. The new semantics make maintaining old 's->index' until check permits increment explicit.
Index is increased at the start, but reduced to old value again if the conditional at the end requires. For ordered bits, left-shifts are done before final right-shift to shield valuable bits against loss through overflow in the last transformation.