load_3(const unsigned char *in)
{
    uint64_t result, tmp;

    tmp = (uint64_t) in[0];
    result = tmp;

    tmp = (uint64_t) in[1];
    tmp <<= 8;
    result |= tmp;

    tmp = (uint64_t) in[2];
    tmp <<= 16;
    result |= tmp;

    return result;
}