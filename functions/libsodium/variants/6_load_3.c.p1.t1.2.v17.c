unsigned long long load_3(const unsigned char *in)
{
    unsigned long long result;

    result = (unsigned long long) in[2] << 16;
    result |= (unsigned long long) in[1] << 8;
    result |= in[0];

    return result;
}