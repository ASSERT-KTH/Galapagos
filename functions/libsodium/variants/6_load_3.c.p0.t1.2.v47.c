load_3(const unsigned char *in)
{
    uint64_t result;

    uint64_t r0 = in[0];
    uint64_t r1 = in[1] << 8;
    uint64_t r2 = in[2] << 16;

    result = r0;
    result |= r1;
    result |= r2;

    return result;
}