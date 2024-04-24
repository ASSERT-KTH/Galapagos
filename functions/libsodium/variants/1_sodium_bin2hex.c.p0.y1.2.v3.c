char *
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    const char lookup[] = "0123456789abcdef";
     
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
     
    for (size_t i = 0; i < bin_len; ++i) {
        hex[i * 2] = lookup[bin[i] >> 4];
        hex[i * 2 + 1] = lookup[bin[i] & 0xf];
    }
    hex[bin_len * 2] = 0;
     
    return hex;
}
