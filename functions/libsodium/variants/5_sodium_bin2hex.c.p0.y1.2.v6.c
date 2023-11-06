Here's an alternative C code implementation:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    size_t i = (size_t) 0U;
    size_t j = (size_t) 0U;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    for(i=0, j=0; i<bin_len; i++) {
        unsigned char byte = bin[i];
        char high = (hex_letters[(byte & 0xF0) >> 4]);
        char low = (hex_letters[(byte & 0x0F)]);
        
        hex[j++] = high;
        hex[j++] = low;
    }
    
    hex[j] = 0U; 

    return hex;
}

Please note that you have to define `hex_letters` as a constant with 16 hexadecimal digits:

static const char *hex_letters = "0123456789abcdef";

This implementation might reduce performance since it adds an extra loop index variable update and may consume more memory to store `hex_letters`. Please take these into consideration when deciding to replace the original function.
