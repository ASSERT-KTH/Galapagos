uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        result |= ((uint64_t)in[i]) << (i * 8);
    }

    return result;
}