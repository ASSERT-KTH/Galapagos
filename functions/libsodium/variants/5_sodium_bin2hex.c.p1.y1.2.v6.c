1. Reversing the order of character assignments within the while loop:


char* sodium_bin2hex(char* const hex, const size_t hex_maxlen,
                     const unsigned char* const bin, const size_t bin_len)
{
    size_t       i = 0U;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }
    while (i < bin_len) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U + 1U] = (char) x;
        x >>= 8;
        hex[i * 2U] = (char) x;
        i++;
    }
    hex[i * 2U] = 0U;

    return hex;
}


2. Using for-loop alternative:


char* sodium_bin2hex(char* const hex, const size_t hex_maxlen,
                     const unsigned char* const bin, const size_t bin_len)
{
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (size_t i = 0U; i < bin_len; ++i) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    }
    hex[bin_len * 2U] = 0U;

    return hex;
}
