Here is a directly equivalent function, just with some measures to reduce the amount of bitwise shenanigans going on:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{   
    const char hex_lut[] = "0123456789abcdef";

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }     

    for (size_t i = 0; i < bin_len; i++) {
        hex[i * 2] = hex_lut[(bin[i]>>4)];
        hex[i * 2 + 1] = hex_lut[(bin[i]&0x0F)];
    }
    
    hex[bin_len * 2] = '\0';

    return hex;
}


This version uses a lookup table instead to fetch the corresponding hexadecimal character value for each 4-bit chunk of byte. This approach makes the implementation bit clearer and readable yet provide the same functionality as per the requirement `maintaining the orginal function's signature`.