char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned char b, c;
    uint16_t     x;

    if (bin_len > hex_maxlen / 2) {
        sodium_misuse(); 
    }
    for (i = 0U; i < bin_len; ++i) {
        b = bin[i] >> 4;
        c = bin[i] & 0xf;
        hex[2*i]     = (char)(87U + b + (((b - 10U) >> 8) & ~38U));
        hex[2*i + 1U] = (char)(87U + c + (((c - 10U) >> 8) & ~38U));
    }
    hex[2*i] = 0U;

    return hex;
}