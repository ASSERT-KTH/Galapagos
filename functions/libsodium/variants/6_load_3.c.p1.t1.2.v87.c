unsigned long long load_3(const unsigned char *in)
{
    unsigned long long result = 0;

    for (int i = 0; i < 3; i++)
    {
        result |= ((unsigned long long) in[i]) << (8 * i);
    }

    return result;
}