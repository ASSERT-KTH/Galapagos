unsigned load_3(const unsigned char *in)
{
    unsigned result;
    result = ((unsigned) in[2]) << 16;
    result |= ((unsigned) in[1]) << 8;
    result |= (unsigned) in[0];
    return result;
}