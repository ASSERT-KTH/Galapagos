char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                 const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
        return NULL;
    }

    for (size_t i = 0; i < bin_len; ++i) {
        uint8_t firstHalf = bin[i] & 0xf, secondHalf = bin[i] >> 4;
        unsigned int parsedFirstHalf = (unsigned char)(87U + firstHalf + ((firstHalf - 10U) >> 8 & ~38U)) << 8 |
                        (unsigned char)(87U + secondHalf + ((secondHalf - 10U) >> 8 & ~38U));
        hex[i * 2U] = parsedFirstHalf;
        hex[i * 2U + 1U] = parsedFirstHalf >> 8;
    }
    hex[bin_len * 2U] = 0U;
    return hex;
}