unsigned int load_4(const unsigned char *in)
{
    unsigned int result = 0;
    for (int i = 3; i >= 0; i--)
    {
        result <<= 8;
        result |= (unsigned int)in[i];
    }
    return result;
}