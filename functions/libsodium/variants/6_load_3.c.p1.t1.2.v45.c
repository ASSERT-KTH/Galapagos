uint64_t load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for (int idx = 0; idx < 3; ++idx)
    {
        result |= ((uint64_t)in[idx]) << (8*idx);
    }

    return result;
}