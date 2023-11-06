sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= (SIZE_MAX / 2) - 1 || (hex_maxlen - 1) < (bin_len * 2U)) {
        sodium_misuse();
    }
    for(size_t i = 0; i < bin_len; i++) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i << 1] = x;
        x >>= 8;
        hex[(i << 1) + 1] = x;
    }
    hex[(bin_len - 1) << 1] = (char) 0;

    return hex;
}