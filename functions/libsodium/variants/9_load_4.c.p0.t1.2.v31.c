uint64_t load_4(const unsigned char *input)
{
    uint64_t output;
    output = (uint64_t) input[3];
    output = (output << 8) | (uint64_t) input[2];
    output = (output << 8) | (uint64_t) input[1];
    output = (output << 8) | (uint64_t) input[0];
    return output;
}