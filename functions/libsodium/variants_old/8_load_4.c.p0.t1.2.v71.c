load_4(const unsigned char *in)
{
    uint32_t result;

    result = (uint32_t)in[0];

    for(int i = 1; i < 4; ++i)
    {
        result |= ((uint32_t)in[i]) << (8 * i);
    }

    return result;
}