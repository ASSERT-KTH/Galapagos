unsigned int load_4(const unsigned char *in)
{
    return  ((unsigned int) in[0])       |
            ((unsigned int) in[1]) << 8  |
            ((unsigned int) in[2]) << 16 |
            ((unsigned int) in[3]) << 24;
}