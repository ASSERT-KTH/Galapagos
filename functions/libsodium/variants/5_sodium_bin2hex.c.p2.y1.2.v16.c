sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
        return NULL;
    }

    size_t       i = (size_t) 0U;
    unsigned int x;
    int          c;
    int          b;

    for (i = 0U; i < bin_len; i++) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U));

        hex[i * 2U + 1U] = (char) (x >> 8);
        hex[i * 2U] = (char) x;
    }

    hex[i * 2U] = 0U;

    return hex;
}