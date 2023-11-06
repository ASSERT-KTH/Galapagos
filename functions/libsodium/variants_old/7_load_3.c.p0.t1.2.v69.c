Variant Function:

load_3(const unsigned char *in)
{
    uint64_t result;
    result = ((uint64_t) in[0]) << 8;
    result |= ((uint64_t) in[1]) << 16;
    result |= (uint64_t) in[2];
    return result;
}
