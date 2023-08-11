Here is a program variant of your code:


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t temp       = s->buffer[index >> 3];
    uint8_t result;

#ifdef BITSTREAM_READER_LE
    result = (temp >> (index & 7)) & 1;
#else
    uint8_t mask = 1 << (7 - (index & 7));
    result = (temp & mask) ? 1 : 0;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        ++s->index;

    return result;
}


In this version, it eliminates hiding **memory** index increment and **result** calculation using bitwise operation in separatelines for code readability and maintainability. While maintaining its original functionality accurately, some might find this version easier to understand.