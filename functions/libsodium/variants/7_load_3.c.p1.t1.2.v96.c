unsigned long long load_3(const unsigned char *in)
{
    unsigned long long result;
    result = (unsigned long long) in[2];
    result = (result << 8) | in[1];
    result = (result << 8) | in[0];
    return result;
}