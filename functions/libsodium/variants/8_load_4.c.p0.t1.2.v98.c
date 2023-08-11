load_4(const unsigned char *in)
{
    int i;
    uint64_t result = 0;

    for (i = 0; i < 4; i++)
    {
        result |= ((uint64_t) in[i]) << (i * 8);
    }

    return result;
}