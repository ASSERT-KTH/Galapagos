load_4(const unsigned char *in)
{
    uint64_t result = 0;

    for (int shift = 0; shift < 4; ++shift)
    {
        result |= ((uint64_t) in[shift]) << (shift * 8);
    }

    return result;
}