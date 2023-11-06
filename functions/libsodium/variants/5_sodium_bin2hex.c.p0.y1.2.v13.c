Here is an alternative implementation for the function "sodium_bin2hex". This newly written version achieves the same functionality in a slightly different way.


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len) {
                         
    static char hexchars[] = "0123456789abcdef";
    size_t i;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); // Same function call when inputs do not meet requirements
    }
  
    for (i = 0; i < bin_len; ++i) {
        hex[i * 2U] = hexchars[(bin[i] >> 4) & 0xF]; 
                         // Here hex_nibbbles are extracted one-by-one starting from nibble with higher significance.

        hex[i * 2U + 1U] = hexchars[bin[i] & 0xF];
                         // Lower 4 bits are masked and corresponding hex character is extracted to be assigned in result.
    }
    hex[i * 2U] = 0U; // Null terminate the string

    return hex;
}

This function extracts nibbles (4 bits) one-by-one from the binary data, then masks the lower 4 bits. It matches them to a lookup table, i.e., 'hexchars', and converts them to hexadecimal form, and finally constructs the hexadecimal string on properly allocated memory as expected.
So this provides the equivalent function as the previous one.