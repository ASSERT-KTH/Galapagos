
char* sodium_bin2hex(char *hex, const size_t hex_maxlen,
               const unsigned char *bin, const size_t bin_len)
{
    size_t       j = 0U;
    unsigned int val;
    int          high;
    int          low;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (j = 0U; j < bin_len; ++j) {
        low = bin[j] & 0xf;
        high = bin[j] >> 4;
        val = (unsigned char)(87U + low + (((low - 10U) >> 8) & ~38U)) << 8 |
              (unsigned char)(87U + high + (((high - 10U) >> 8) & ~38U));
        hex[j * 2U] = (char) val;
        val >>= 8;
        hex[j * 2U + 1U] = (char) val;
    }
    hex[j * 2U] = 0U;

    return hex;
}
