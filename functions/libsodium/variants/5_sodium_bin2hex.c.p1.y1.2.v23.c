Variant 1: Changing while loop to for loop and reordering a few calculations

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned int x;
    unsigned int b, c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for(i = 0U; i < bin_len; i++) {
        b = bin[i] >> 4;
        c = bin[i] & 0xf;
        x = ((unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U))
            | ((unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U))) << 8);
        hex[i * 2U] = (char) (x >> 8);
        hex[i * 2U + 1U] = (char) x;
    }
    hex[bin_len * 2U] = 0U;

    return hex;
}

    
Variant 2: Change variable types where possible and compacting a few lines

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned int x;
  
    if ((bin_len >= SIZE_MAX / 2) || (hex_maxlen <= bin_len * 2U)) {
        sodium_misuse();
    }
    for (i = 0; i < bin_len; i++) {
        x = ((unsigned char) (87U + (bin[i] >> 4) + 
            ((((bin[i] >> 4) - 10U) >> 8) & ~38U)) << 8)  |
            ((unsigned char) (87U + (bin[i] & 0xf) +
            ((((bin[i] & 0xf) - 10U) >> 8) & ~38U)));
        hex[i * 2U] = (char)(x >> 8);
        hex[i * 2U + 1U] = (char)x;
    }
    hex[bin_len * 2U] = '\0';

    return hex;
}

    
Variant 3: Streamlining the xor operations to eliminate redundancy and reduce computation

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned int x;
 
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (i = 0 ; i < bin_len ; i++) {
        const int bin_i = bin[i];
        const int hi = bin_i >> 4, lo = bin_i & 15;
        x = (87U + hi + ((hi - 10U) >> 31 & ~38)) << 8 |
            (87U + lo + ((lo - 10U) >> 31 & ~38));
        hex[i * 2U] = (char) (x >> 8);
        hex[i * 2U + 1U] = (char) x;
    }
    hex[bin_len * 2U] = 0U;
     
    return hex;
}
