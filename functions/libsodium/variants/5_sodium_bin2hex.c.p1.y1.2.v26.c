// Variant 1:
char *sodium_bin2hex_v1(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{
    size_t i = 0U;
    unsigned int x;
    int lowNibble;
    int highNibble;
    
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }

    for(; i<bin_len; ++i){
        lowNibble = bin[i] & 0xf;
        highNibble = bin[i] >> 4;
        x = (unsigned char) (87U + lowNibble + (((lowNibble - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + highNibble + (((highNibble - 10U) >> 8) & ~38U));

        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    }
    
    hex[i * 2U] = 0U;

    return hex;
}

// Variant 2:
char *sodium_bin2hex_v2(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{
    unsigned int x;
    int lowNibble;
    int highNibble;
    
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }

    for(size_t i = 0U; i<bin_len; ++i){
        lowNibble = bin[i] & 0xf;
        highNibble = bin[i] >> 4;
        x = (unsigned char) (87U + lowNibble + (((lowNibble - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + highNibble + (((highNibble - 10U) >> 8) & ~38U));

        hex[i * 2U] = (char) (x >> 8);
        hex[i * 2U + 1U] = (char) x;
    }
    
    hex[bin_len * 2U] = 0U;

    return hex;
}