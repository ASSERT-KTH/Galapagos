char *sodium_bin2hex(char *hex, const size_t hex_maxlen,
                     const unsigned char *bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    else {
        size_t       i;
        unsigned int x;
        int          b;
        int          c;

        for (i = 0; i < bin_len; ++i) {
            c = bin[i] & 0xf;
            b = bin[i] >> 4;
            x = (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U)) << 8 |
                (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U));
            
            hex[i * 2U + 1U] = (char) (x >> 8);
            hex[i * 2U] = (char) x;
        }
        hex[i * 2U] = '\0';
    }

    return hex;
}