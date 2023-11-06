uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;
    for (int i=0; i<4; i++)
    {
        result |= ((uint64_t) in[i]) << (8 * i);
    }
    return result;
}