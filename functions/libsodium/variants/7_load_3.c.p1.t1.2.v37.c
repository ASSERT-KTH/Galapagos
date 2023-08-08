ulong load_3(const unsigned char *in)
{
    uint64_t res;
    res = (uint64_t) (in[0] | (in[1] << 8) | (in[2] << 16));
    return res;
}