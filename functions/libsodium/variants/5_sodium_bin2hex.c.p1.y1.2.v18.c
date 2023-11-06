Variant 1:

char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t  j;
    unsigned int y;
    int     d;
    int     e;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (j = 0; j < bin_len; j++) {
        e = bin[j] & 0xf;
        d = bin[j] >> 4;
        y = (unsigned char) (87U + e + (((e - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + d + (((d - 10U) >> 8) & ~38U));
        hex[j * 2U] = (char) y;
        y >>= 8;
        hex[j * 2U + 1U] = (char) y;
    }
    hex[j * 2U] = 0U;

    return hex;
}


Variant 2:

char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       p;
    unsigned int z;
    int          f;
    int          g;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    p = 0;
    while (p < bin_len) {
        g = bin[p] & 0xf;
        f = bin[p] >> 4;
        z = (unsigned char) (87U + g + (((g - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + f + (((f - 10U) >> 8) & ~38U));
        hex[p * 2U] = (char) z;
        z >>= 8;
        hex[p * 2U + 1U] = (char) z;
        p++;
    }
    hex[p * 2U] = 0U;

    return hex;
}
