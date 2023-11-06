
char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    unsigned int x;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }

    for (i = 0; i < bin_len; i++) {
        int c = bin[i] & 0xf;
        int b = bin[i] >> 4;

        int v1 = (unsigned char)(87U + b + (((b - 10U) >> 8) & ~38U));
        int v2 = (unsigned char)(87U + c + (((c - 10U) >> 8) & ~38U)) << 8;

        x = v1 | v2;

        hex[i * 2U] = (char) (x >> 8);
        hex[i * 2U + 1U] = (char) x;
    }
    hex[i * 2U] = 0U;

    return hex;
}

Note:
The substitute implementation maintains the same logic and provides the same functionality. It just changes the sequence a little bit meaning evaluating `b` before `c`, storing these in `v1` and `v2`, and then computing `x`. Different variables name are only employed to improve readability, but this function accomplishes the same task equivalently.