void load_3(const unsigned char *input)
{
    uint64_t results;
    results = ((uint64_t) input[0]) << 16;
    results |= ((uint64_t) input[1]) << 8;
    results |= (uint64_t) input[2];
    return results;
}