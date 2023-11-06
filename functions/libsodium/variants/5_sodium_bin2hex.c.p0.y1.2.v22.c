char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    static char const hex_chars[] = "0123456789abcdef";

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    for(size_t i =0; i< bin_len; ++i) {
        hex[i * 2U] = hex_chars[(bin[i] & 0xF0U) >> 4U];
        hex[i * 2U + 1U] = hex_chars[bin[i] & 0x0FU];
    }

    hex[bin_len * 2U] = '\0';

    return hex;
}