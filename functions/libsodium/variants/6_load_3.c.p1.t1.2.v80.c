You can write a program variant as follows:

unsigned long long load_3(const unsigned char *in)
{
    unsigned long long result = 0;
    int i;

    for (i = 0; i < 3; i++)
    {
        result <<= 8;
        result |= in[i];
    }

    return result;
}