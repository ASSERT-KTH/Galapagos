1. Swapping the order of byte processing inside the loop:


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i = (size_t)0U;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    while (i < bin_len) {
        b = bin[i] >> 4;
        c = bin[i] & 0xf;
        x = (unsigned char)(87U + c + ((c - 10U) >> 8 & ~38U)) << 8 |
           (unsigned char)(87U + b + ((b - 10U) >> 8 & ~38U));
        hex[i * 2U]     = (char)x;
        x >>= 8;
        hex[i * 2U + 1U] = (char)x;
        i++;
    }
    hex[i * 2U] = 0U;

    return hex;
}


2. Using prefix increment operation inside loop:


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i = (size_t)0U;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    while (i < bin_len) {
        c = bin[i] & 0xf;
        b = bin[i++] >> 4;
        x = (unsigned char)(87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char)(87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U - 2U] = (char)x;
        x >>= 8;
        hex[i * 2U - 1U] = (char)x;
    }
    hex[i * 2U] = 0U;

    return hex;
}
  

3. Initializing the variable `i` while declaring it:


sodium_bin2hex(char *const hex, const size_t hex_maxlen, 
                const unsigned char *const bin, const size_t bin_len)
{
    for (size_t i = 0U, c, b, x; i < bin_len; i++) {
        if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
            sodium_misuse();
        }
        
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char)(87U + c + (((c - 10U) >> 8) & ~38U)) << 8 | 
            (unsigned char)(87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char)x;
        x >>= 8;
        hex[i * 2U + 1U] = (char)x;
    }
    hex[i * 2U] = 0U;
    return hex;
}
