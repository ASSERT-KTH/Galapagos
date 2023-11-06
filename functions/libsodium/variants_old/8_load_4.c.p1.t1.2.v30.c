The following is the changed variant of the function while preserving its functionality and functionality signature:


uint64_t load_4(const unsigned char *in) 
{
    uint64_t result = 0;
    for (int i = 0; i < 4; ++i)
    {
        result |= ((uint64_t) in[i]) << (i * 8);
    }
    return result;
}


This version does virtually the same thing but applied in a loop instead of using separate lines for each variable. This makes the function more flexible to changes and easier to upscale. However, this variant is a bit slower due to the extra control fixed overhead with loop initialization, comparison, and increment operations.