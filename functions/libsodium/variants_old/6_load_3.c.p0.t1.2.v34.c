unsigned long long load_3(const unsigned char *input)
{
    unsigned long long res;

    res = 0;
    res += input[0];
    res += (unsigned long long) input[1] << 8;
    res += (unsigned long long) input[2] << 16;

    return res;
}