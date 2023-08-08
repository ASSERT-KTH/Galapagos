unsigned long long load_3(const unsigned char *in)
{
    unsigned long long result;

    result = in[0];
    result += in[1] * 256;
    result += in[2] * 65536;

    return result;
}