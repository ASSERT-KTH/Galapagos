load_3_rev(const unsigned char *in)
{
    uint64_t result;

    result = (uint64_t) in[2];
    result |= ((uint64_t) in[1]) << 8;
    result |= ((uint64_t) in[0]) << 16;

    return result;
}