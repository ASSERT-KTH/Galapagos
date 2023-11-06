unsigned long load_3(const unsigned char *in)
{
    unsigned long result;

    result = (unsigned long) in[0];
    result |= ((unsigned long) in[1]) << 8;
    result |= ((unsigned long) in[2]) << 16;

    return result;
}