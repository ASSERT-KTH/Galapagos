The original C function is probably for constructing a 32-bit relative integer from a character-type array. Below is a valid variant that maintains its functionality:


uint64_t load_4(const unsigned char *in)
{
    uint64_t result;
    for (int i = 0; i < 4; ++i)
    {
        result |= ((uint64_t) in[i]) << (8 * i);
    }
    return result;
}
 

In this version, a for-loop distinctly indicates the iterations over the array `in[]`. The left bit shift in each iteration increments by `8` through `(8 * i)`, aligning to the specifics of a 32-bit construction. The overall code readability has improved.