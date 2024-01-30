Here's a variant that implements the same functionality as the original function, however, it tweaks the sequence of operations, courtesy the properties of bitwise operators.


static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8]; // Shift right by 3 does the same thing as dividing by 8

#ifdef BITSTREAM_READER_LE
    result &= (1U << (index % 8)) - 1; // AND operation with 2^n - 1 eliminates high bits, keeping the behavior the same
    result >>= index % 8;
#else
    result = (result << (index % 8)) & 0xFF; // Somewhat gratuitous AND to make sure shifting doesn't introduce spare bits
    result >>= 8 - 1;
#endif

#if !UNCHECKED_BITSTREAM_READER
    if (index < s->size_in_bits_plus8) // It makes more sense to compare the original index, not the possibly incremented one
#endif
        s->index = index + 1;

    return result;
}


This does the same thing but handles manipulating the result a little bit differently. It also directly increments the `index` in struct `s`. The whole point is to show different ways to accomplish the original task; making one equivalent function to another in different manners.
