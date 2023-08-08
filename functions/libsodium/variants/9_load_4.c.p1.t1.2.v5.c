uint64_t load_4(const unsigned char *in)
{
    uint64_t result;
    result = (uint64_t) (in[3] << 24 |
                         in[2] << 16 |
                         in[1] << 8  |
                         in[0]);
    return result;
}