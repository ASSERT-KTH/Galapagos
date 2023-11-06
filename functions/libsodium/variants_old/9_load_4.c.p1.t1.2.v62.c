unsigned long long load_4(const unsigned char *in)
{
    unsigned long long result;
    result = ((unsigned long long) *(in)) | ((unsigned long long) *(in + 1) << 8) | ((unsigned long long) *(in + 2) << 16) | ((unsigned long long) *(in + 3) << 24);
    return result;
}