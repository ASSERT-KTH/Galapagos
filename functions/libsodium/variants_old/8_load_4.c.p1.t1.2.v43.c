unsigned long long int load_4(const unsigned char *in)
{
    unsigned long long int result = 0;
    int shift = 0;

    for(int i = 0; i < 4; i++)
    {
        result |= ((unsigned long long int) in[i]) << shift;
        shift += 8;
    }

    return result;
}