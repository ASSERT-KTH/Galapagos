load_4(const unsigned char *in)
{
    uint64_t result;

    result = static_cast<uint64_t>(in[0]);
    result += (static_cast<uint64_t>(in[1])) << 8;
    result += (static_cast<uint64_t>(in[2])) << 16;
    result += (static_cast<uint64_t>(in[3])) << 24;

    return result;
}