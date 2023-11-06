unsigned long long load_3(const unsigned char *in)
{
    unsigned long long result = 0;

    result += (unsigned long long) in[0];
    result += ((unsigned long long) in[1]) << 8;
    result += ((unsigned long long) in[2]) << 16;

    return result;
}