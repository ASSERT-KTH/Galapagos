unsigned int load_3(const unsigned char *in)
{
    unsigned int result;
    result = (unsigned int) in[0];
    result |= ((unsigned int) in[1]) << 8;
    result |= ((unsigned int) in[2]) << 16;
    return result;
}