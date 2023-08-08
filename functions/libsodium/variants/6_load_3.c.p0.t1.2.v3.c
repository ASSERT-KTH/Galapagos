unsigned char load_3(const unsigned char *in)
{
    unsigned char result;

    result = (unsigned char) in[0];
    result |= ((unsigned char) in[1]) << 8;
    result |= ((unsigned char) in[2]) << 16;

    return (uint64_t)result;
}