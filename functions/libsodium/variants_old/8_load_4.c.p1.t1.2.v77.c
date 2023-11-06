unsigned int load_4(const unsigned char *in)
{
    unsigned int result;

    result  = in[0];
    result += in[1] << 8;
    result += in[2] << 16;
    result += in[3] << 24;

    return result;
}