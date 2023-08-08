load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for (int shift = 0, i = 0; i < 3; ++i, shift += 8)
    {
        result |= ((uint64_t)in[i]) << shift;
    }
 
    return result;
}