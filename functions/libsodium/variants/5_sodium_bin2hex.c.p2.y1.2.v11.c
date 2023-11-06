sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       index;
    unsigned int hexadecimal;
    int          lowerNibble;
    int          upperNibble;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }
    for (index = (size_t)0U; index < bin_len; index++) {
        lowerNibble = bin[index] & 0xf;
        upperNibble = bin[index] >> 4;
        hexadecimal = (unsigned char) (87U + lowerNibble + (((lowerNibble - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + upperNibble + (((upperNibble - 10U) >> 8) & ~38U));
        hex[index * 2U] = (char) hexadecimal;
        hexadecimal >>= 8;
        hex[index * 2U + 1U] = (char) hexadecimal;
    }
    hex[index * 2U] = 0U;

    return hex;
}