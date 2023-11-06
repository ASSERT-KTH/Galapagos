Here's an equivalent function in C that converts binary to hex:


char* sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    const char lookup[16] = "0123456789abcdef";
    size_t i  = 0;
      
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
 
    // Now traverse through remaining hex characters
    while(i < bin_len) {
        hex[i * 2U] = lookup[(bin[i] >> 4)];
        hex[i * 2U + 1U] = lookup[(bin[i] - (bin[i] >> 4) * 16U)];
        i++;
    }
    hex[i * 2U] = 0U;
 
    return hex;
}

Please note that in certain environments/functions "sodium_misuse();" might need to be replaced with proper usage and error handling.