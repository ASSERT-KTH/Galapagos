load_4(const unsigned char *in)
{
    unsigned int result = 0;
    result = (unsigned int) in[0] | ((unsigned int) in[1] << 8) | ((unsigned int) in[2] << 16) | ((unsigned int) in[3] << 24);
    return result;
}