
uint64_t load_3(const unsigned char *in)
{
    return ((uint64_t) in[0])
    | (((uint64_t) in[1]) << 8)
    | (((uint64_t) in[2]) << 16);
}
