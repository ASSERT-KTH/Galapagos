Here's an alternative function in C:


char* sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    const char *hexmap = "0123456789abcdef";
    size_t i = 0U;
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    for (; i < bin_len; i++) {
        hex[2 * i] = hexmap[(bin[i] & 0xF0) >> 4];
        hex[2 * i + 1] = hexmap[bin[i] & 0x0F];
    }
    hex[i * 2U] = 0U;
    return hex;
}
