unsigned long load_3(const unsigned char *in)
{
    unsigned long result = 0;
    result = in[2];
    result = (result << 8) | in[1];
    result = (result << 8) | in[0];
    return result;
}