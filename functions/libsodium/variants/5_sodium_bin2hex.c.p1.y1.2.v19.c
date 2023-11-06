Variant #1

char *sodium_bin2hex_alt1(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    size_t i, x;
    int b, c;
    
    if (bin_len<0 || bin_len>=SIZE_MAX/2 || hex_maxlen <= bin_len*2U) {
       sodium_misuse();
    }
    for (i = 0; i < bin_len; ++i) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        
        x = ((unsigned int)(87U + c + (((c - 10U) >> 8) & ~38U)) << 8) | ((unsigned int)(87U + b + (((b - 10U) >> 8) & ~38U)));
        hex[i*2] = (char)x;
        x >>= 8;
        hex[i*2+1] = x;
    }
    hex[i*2] = '\0';

    return hex;
}
 

Variant #2

char *sodium_bin2hex_alt2(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    size_t       i;
    unsigned int x;
    int          b;
    int          c;

    // error handling
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    // Loop through each byte in bin
    for (i = 0; i < bin_len; i++){
        c = bin[i] & 0xf;    // Get lower nibble(first 4 bits)
        b = bin[i] >> 4;     // Get upper nibble(last 4 bits)

        x = ((unsigned int) (87 + c + (((c - 10) >> 8) & ~38)) << 8) |  ((unsigned int) (87 + b + (((b - 10) >> 8) & ~38)));
        hex[i * 2] = x;
        x >>= 8;
        hex[i * 2 + 1] = x;
    }

    // Null-terminate the hex string
    hex[i * 2] = 0;

    return hex;
}
