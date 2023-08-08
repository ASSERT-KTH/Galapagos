Here's the program variant:


uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;
    for (int i = 0; i < 4; i++)
    {
        result |= ((uint64_t) in[i]) << (i * 8);
    }
    return result;
}


This function does the same converting job with a loop approach rather than writing each operation on its own line. It maintains the original functionality while updating the style of the original code.