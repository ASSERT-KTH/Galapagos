Variant 1: Removing intermediate variables `b` and `c` -


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len) {
    size_t       i = (size_t) 0U;
    unsigned int x;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* Will never be executed */
    }

    while (i < bin_len) {
        x = (unsigned char) (87U + (bin[i] & 0xf) + ((((bin[i] & 0xf) - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + (bin[i] >> 4) + ((((bin[i] >> 4) - 10U) >> 8) & ~38U));
        
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    
        i++;
    }

    hex[i * 2U] = 0U;

    return hex;
}
 
Variant 2: Reorganizing bitwise logic -


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len) {
    size_t       i = (size_t) 0U;
    unsigned int x;
    unsigned int c;
    unsigned int c_shifted;
    unsigned int b;
    unsigned int b_shifted;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* Will never be executed */
    }

    while (i < bin_len) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        c_shifted = c - 10U;
        b_shifted = b - 10U;
        x = (unsigned char) (87U + c) + ((c_shifted >> 8) & ~38U) << 8 |
            (unsigned char) (87U + b) + ((b_shifted >> 8) & ~38U);
        
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    
        i++;
    }

    hex[i * 2U] = 0U;

    return hex;
}
