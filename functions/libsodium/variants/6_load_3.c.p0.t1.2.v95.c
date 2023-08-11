load_3(const unsigned char *in)
{
    uint64_t result = 0u;

    result = (uint64_t) in[2];
    result |= ((uint64_t) in[1]) << 16;
    result |= ((uint64_t) in[0]) << 24;

    return result;
}