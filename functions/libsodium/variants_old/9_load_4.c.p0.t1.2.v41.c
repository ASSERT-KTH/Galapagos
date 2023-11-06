uint64_t load_4(const unsigned char *in)
{
    uint64_t result = (uint64_t) in[0];

    unsigned int shift_amount = 8;
    for (int i = 1; i < 4; ++i) {
        result |= ((uint64_t) in[i]) << shift_amount;
        shift_amount += 8;
    }

    return result;
}