uint64_t load_3(const unsigned char *in)
{
    uint64_t result;

    result = (uint64_t) in[2];
    result = result << 16 | ((uint64_t) in[1]) << 8;
    result = result | (uint64_t) in[0];

    return result;
}