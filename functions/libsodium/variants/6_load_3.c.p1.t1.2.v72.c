
uint64_t load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for(int i = 0; i < 3; i++) 
    {
        result |= ((uint64_t) in[i]) << (8 * i);
    }

    return result;
}

In this version, a for loop is used to achieve the same functionality as the original function. The incoming data (in[i]) is shifted to the left by 8 bits times i, then logically OR'd with the current result. This variant behaves exactly the same as the original, combining the three bytes in 'in' into a single uint64_t value.