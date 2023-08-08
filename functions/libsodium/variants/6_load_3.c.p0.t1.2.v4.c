load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for (int i = 2; i >= 0; --i) 
    {
        result = result << 8;
        result |= in[i];
    }

    return result;
}