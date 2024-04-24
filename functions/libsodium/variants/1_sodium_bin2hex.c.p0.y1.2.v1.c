char *
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t i = 0U;
    unsigned int x;
    int upper, lower;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    for (i = 0U; i < bin_len; ++i) {
        lower = bin[i] & 0xf;
        upper = bin[i] >> 4;
        x = ((87U + lower + ((lower - 10U >> 8) & ~38U))) |
            ((87U + upper + ((upper - 10U >> 8) & ~38U)) << 8);
        hex[2 * i + 0] = (char) (x & 0xff);
        hex[2 * i + 1] = (char) (x >> 8);
    }
    
    hex[i * 2U] = '\0';

    return hex;
}
