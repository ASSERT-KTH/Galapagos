unsigned long int load_3(const unsigned char *in)
{
    unsigned long int result;
    result = 0;
    result = result | ((unsigned long int) in[0]);
    result = result | ((unsigned long int) in[1]) << 8;
    result = result | ((unsigned long int) in[2]) << 16;
    return result;
}