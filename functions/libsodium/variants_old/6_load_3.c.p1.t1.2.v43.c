unsigned long long int load_3(const unsigned char *in)
{
    unsigned long long int result;

    result = 0;
    result += ((unsigned long long int) in[0]);
    result += ((unsigned long long int) in[1]) << 8;
    result += ((unsigned long long int) in[2]) << 16;

    return result;
}