unsigned long long int load_3(const unsigned char *in)
{
    unsigned long long int result = 0;

    for (int i = 0; i < 3; i++)
    {
        result |= ((unsigned long long int) in[i]) << (i * 8);
    }

    return result;
}