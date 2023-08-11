uint64_t load_4(const unsigned char *in)
{
    uint64_t result;
    
    result = in[0];
    result = result << 8 | in[1];
    result = result << 8 | in[2];
    result = result << 8 | in[3];

    return result;
}