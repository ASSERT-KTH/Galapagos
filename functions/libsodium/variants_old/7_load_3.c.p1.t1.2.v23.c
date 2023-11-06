uint64_t load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for(int i = 0; i < 3; i++)
    {
        result <<= 8;
        result |= in[i];
    }

    return result;
}