uint64_t load_4(const unsigned char *in) 
{
    uint64_t result = 0;
    for (int i = 3; i >= 0; i--) 
    {
        result <<= 8;
        result |= in[i];
    }
    return result;
}