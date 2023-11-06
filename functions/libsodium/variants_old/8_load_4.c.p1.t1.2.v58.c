unsigned long load_4(const unsigned char *in)
{
    unsigned long res = 0;
    int i;

    for(i = 0; i < 4; i++)
    {
        res = (res << 8) | in[i];
    }

    return res;
}