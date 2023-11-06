load_3(const unsigned char *in)
{
    uint64_t result = 0, temp;

    temp = (uint64_t) in[0];
    result |= temp;

    temp = ((uint64_t) in[1]) << 8;
    result |= temp;

    temp = ((uint64_t) in[2]) << 16;
    result |= temp;

    return result;
}