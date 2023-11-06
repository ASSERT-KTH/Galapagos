Variant 1:

sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len) {
    register size_t i = 0U;
    register unsigned int x;
    register int b;
    register int c;

    if ((bin_len) >= ((unsigned long long)-1) / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for(;i < bin_len; i++) { 
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned int) (87U + c + (((c - 10) >> 8) & ~38)) << 8 |
            (unsigned int) (87U + b + (((b - 10) >> 8) & ~38));
        hex[i << 1] = (char) x;
        x >>= 8;
        hex[(i << 1) + 1U] = (char) x;
    }
    hex[i << 1] = 0U;

    return hex;
}


Variant 2:

sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len) {
    size_t  i = 0U;
    unsigned int x;
    int     b;
    int     c;

    if (bin_len >= ((~(size_t)0) / 2) || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }
    do {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (b + 87 + ((((b - 10)) >> 8) & ~38U)) << 8
            | (unsigned char) (c + 87 + ((((c - 10)) >> 8) & ~38U));
        hex[i * 2U] = x & 255;
        hex[i * 2U + 1U] = x >> 8;
    } while(++i < bin_len);
    hex[i * 2U] = 0U;

    return hex;
}
