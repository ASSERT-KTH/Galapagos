uint64_t load_3(const unsigned char *in)
{
    uint64_t out = 0;
    for (int i = 2; i >= 0; --i) {
        out = (out << 8) | in[i];
    }
    return out;
}