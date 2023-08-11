load_4(const unsigned char *in)
{
    uint32_t low_result;
    uint32_t high_result;
    
    low_result = (uint32_t) in[0];
    low_result |= ((uint32_t) in[1]) << 8;

    high_result = (uint32_t) in[2];
    high_result |= ((uint32_t) in[3]) << 8;

    return ((uint64_t)high_result << 16) | low_result;
}