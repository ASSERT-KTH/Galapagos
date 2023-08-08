void load_4_v2(const unsigned char *in, uint64_t* output)
{
    *output = (uint64_t) in[0];
    *output |= ((uint64_t) in[1]) << 8;
    *output |= ((uint64_t) in[2]) << 16;
    *output |= ((uint64_t) in[3]) << 24;
}