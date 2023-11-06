uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;
    for (int i = 3; i >= 0; i--) {
        result = (result << 8) | in[i];
    }
    return result;
}