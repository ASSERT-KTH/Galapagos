unsigned long load_4(const unsigned char *in)
{
    unsigned long result = 0;

    result += (unsigned long) in[0];
    result += ((unsigned long) in[1]) << 8;
    result += ((unsigned long) in[2]) << 16;
    result += ((unsigned long) in[3]) << 24;

    return result;
}