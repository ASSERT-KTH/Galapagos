unsigned long load_4(const unsigned char *in)
{
    return ((unsigned)in[0]) |
           (((unsigned)in[1]) << 8) |
           (((unsigned)in[2]) << 16) |
           (((unsigned)in[3]) << 24);
}