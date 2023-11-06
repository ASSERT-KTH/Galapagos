unsigned int load_4(const unsigned char *in)
{
    unsigned int result;

    result = (unsigned int) in[0];
    result += ((unsigned int) in[1]) << 8;
    result += ((unsigned int) in[2]) << 16;
    result += ((unsigned int) in[3]) << 24;

    return result;
}