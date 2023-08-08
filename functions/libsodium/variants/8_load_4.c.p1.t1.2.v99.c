unsigned long long load_4(const unsigned char *in)
{
    return (unsigned long long) in[3] << 24 |
           (unsigned long long) in[2] << 16 |
           (unsigned long long) in[1] << 8  |
           (unsigned long long) in[0];
}