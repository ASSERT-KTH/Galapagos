Here's an alternative implementation of sodium_bin2hex function in C:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                    const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }
    for (i = 0; i < bin_len; i++) {
        sprintf(hex + (2 * i), "%02x", bin[i]);
    }
    hex[2 * bin_len] = '\0';
    
    return hex;
}

Note that sprintf(...) function was used which may require to include "stdio.h".