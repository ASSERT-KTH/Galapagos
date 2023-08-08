unsigned char load_4(const unsigned char *in)
{
    unsigned char result;

    result = (unsigned char) in[0];
    result |= ((unsigned char) in[1] << 8);
    result |= ((unsigned char) in[2] << 16);
    result |= ((unsigned char) in[3] << 24);

    return result;
}