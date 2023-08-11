
load_3(const unsigned char *in)
{
    uint64_t result = 0;

    result = ((uint64_t) in[2]) << 16;
    result |= ((uint64_t) in[1]) << 8;
    result |= (uint64_t) in[0]; 

    return result;
}
