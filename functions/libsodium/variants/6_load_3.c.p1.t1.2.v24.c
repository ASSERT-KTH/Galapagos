Here is a refactored version of your function:


load_3(const unsigned char *in)
{
    uint64_t result;

    for (int i = 0; i < 3; ++i)
    {
        result |= ((uint64_t) in[i]) << (i * 8);
    }

    return result;
}


This function does the same task as the original function, but it loops through the input and bit-shifts accordingly instead of doing each manually.