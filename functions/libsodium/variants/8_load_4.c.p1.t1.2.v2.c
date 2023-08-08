uint64_t load_4(const unsigned char *in)
{
    uint64_t result;

    result = ((unsigned char) in[0]) | ((unsigned char) in[1]) << 8 | ((unsigned char) in[2]) << 16 | ((unsigned char) in[3]) << 24;

    return result;
}