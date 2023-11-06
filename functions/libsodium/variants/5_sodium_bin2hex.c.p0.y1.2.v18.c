The below code is an alternate version of the given function which uses snprintf for converting the binary values into hexadecimal.

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    } 

    for (i = 0; i < bin_len; i++) {
        snprintf(hex + (i * 2), 3, "%02x", bin[i]); 
    }

    hex[i*2] = '\0';


    return hex;
};

This alternative version doesn't need auxiliary integer variables, including bitwise operations and related logic; therefore, it's much simpler and easier to understand. Plus, the standard snprintf() function safely writes the bin array elements to the destination hex array in an hexadecimal format (it ensures that no buffer overflow occurs).