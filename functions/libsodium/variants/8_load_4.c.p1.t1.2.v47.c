unsigned int load_4(const unsigned char *in)
{
    return (in[0] | in[1] << 8 | in[2] << 16 | in[3] << 24);
}