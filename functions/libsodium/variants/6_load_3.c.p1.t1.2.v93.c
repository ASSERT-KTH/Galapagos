unsigned long long load_3(const unsigned char *in)
{
    unsigned long long result;

    result = *(in);
    result |= (*(in + 1)) << 8;
    result |= (*(in + 2)) << 16;

    return result;
}