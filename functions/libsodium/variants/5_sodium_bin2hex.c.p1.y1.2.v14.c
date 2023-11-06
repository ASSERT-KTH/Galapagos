Variant 1: Using for loop instead of while loop:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    size_t       i;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (i = 0U; i < bin_len; i++) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    }
    hex[i * 2U] = 0U;

    return hex;
}


Variant 2: Reduce intensity of arithmetic operations by splitting multiple operations into separate lines:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    size_t       i = (size_t) 0U;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    while(i < bin_len) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;

        unsigned char first_value = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U));
        unsigned char second_value = (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));

        x =  first_value << 8 | second_value;
        hex[i * 2U] = (char) x;
        
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;

        i++;
    }
    hex[i * 2U] = 0U;

    return hex;
}
