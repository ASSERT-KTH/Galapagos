Here is a program variant that maintains the same functionality of the original function but changes its behavior by using a loop.


uint64_t load_3(const unsigned char *in)
{
    uint64_t result = 0;
    for (int i = 0; i < 3; i++)
    {
        result |= ((uint64_t) in[i]) << (8 * i);
    }
    return result;
}
