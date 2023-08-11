unsigned char load_4_rev(const unsigned char *in)
{
    uint64_t result;

    result = ((uint64_t) in[3]);
    result |= ((uint64_t) in[2]) << 8;
    result |= ((uint64_t) in[1]) << 16;
    result |= ((uint64_t) in[0]) << 24;

    return result;
}