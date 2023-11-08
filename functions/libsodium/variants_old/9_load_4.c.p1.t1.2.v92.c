uint64_t load_4(const unsigned char *in)
{
    uint64_t result;
    int shift = 0;

    for(int i = 0; i < 4; i++)
    {
        result |= ((uint64_t) in[i]) << shift;
        shift += 8;
    }

    return result;
}