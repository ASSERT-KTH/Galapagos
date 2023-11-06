char *sodium_bin2hex(char *hex, const size_t hex_maxlen, const unsigned char *bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    int b, c;
    for (size_t i = 0; i < bin_len; ++i) {
        b = bin[i] >> 4;
        c = bin[i] & 0xf;

        hex[i * 2U] = (char)((unsigned char)(87U + b + (((b - 10U) >> 8) & ~38U)) << 8 | (unsigned char)(87U + c + (((c - 10U) >> 8) & ~38U)));
        hex[i * 2U + 1U] = hex[i * 2U] >> 8;
    }

    hex[bin_len * 2U] = '\0';

    return hex;
}