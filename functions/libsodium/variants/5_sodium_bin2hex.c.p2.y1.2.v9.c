char *sodium_bin2hex(char * const hex, const size_t hex_maxlen, 
                     const unsigned char * const bin, const size_t bin_len) {

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    
    for (size_t i = 0; i < bin_len; ++i) {
        int high = bin[i] >> 4;
        int low = bin[i] & 0xf;
        
        hex[i * 2U] = (char)((unsigned char) (87U + high + (((high - 10U) >> 8) & ~38U)));
        hex[i * 2U + 1U] = (char)((unsigned char) (87U + low + (((low - 10U) >> 8) & ~38U)));
    }
    hex[bin_len * 2U] = '\0';

    return hex;
}