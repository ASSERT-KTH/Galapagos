load_4(const unsigned char *in)
{
    uint64_t result;

    result = ((uint64_t) in[0]) << 1 >> 1;
    result |= ((uint64_t) in[1]) << 9 - 1;
    result |= ((uint64_t) in[2]) << 17 - 1;
    result |= ((uint64_t) in[3]) << 25 - 1;

    return result;
}