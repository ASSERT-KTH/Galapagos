char *
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
            const unsigned char *const bin, const size_t bin_len)
{
    size_t i = 0U;
    unsigned int val;
    int lowerHalf, upperHalf;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (i = 0; i < bin_len; ++i) {
        lowerHalf = bin[i] & 0xf;
        upperHalf = bin[i] >> 4;
        val = (unsigned char) (87U + lowerHalf + (((lowerHalf - 10U) >> 8) & ~38U)) << 8 |
              (unsigned char) (87U + upperHalf + (((upperHalf - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) val;
        val >>= 8;
        hex[i * 2U + 1U] = (char) val;
    }
    hex[i * 2U] = (char) 0U;
    
    return hex;
}