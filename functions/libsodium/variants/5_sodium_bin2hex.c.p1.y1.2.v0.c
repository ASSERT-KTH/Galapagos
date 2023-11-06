Version 1 (Do a `for` loop instead `while` loop):

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    for (size_t i = 0U; i < bin_len; i++) {
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


Version 2 (Remove interim variables `b`, `c`, `x`):

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t i = 0U;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    while (i < bin_len) {
        hex[i * 2U] = (char) ((unsigned char) (87U + (bin[i] & 0xf) +
                            ((((bin[i] & 0xf) - 10U) >> 8) & ~38U)) << 8 |
                            (unsigned char) (87U + (bin[i] >> 4) +
                           (((bin[i] >> 4) - 10U) >> 8) & ~38U));

        hex[i * 2U + 1U] = (char)  (hex[i * 2U] >> 8);
        i++;
    }
    hex[i * 2U] = 0U;

    return hex;
}


Version 3 (Change hex assignment):

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i = 0U;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    while (i < bin_len) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));

        hex[i * 2U + 1U] = (char) (x >> 8);
        hex[i * 2U] = (char) x;
        i++;
    }
    hex[i * 2U] = 0U;

    return hex;
}
