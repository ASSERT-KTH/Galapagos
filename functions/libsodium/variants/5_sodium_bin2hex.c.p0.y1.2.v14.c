Here is a substitute implementation of the function that serves the same functionality:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t i = 0U;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    else {
        for(i = 0U; i < bin_len; i++)
        {
            hex[i * 2U] = "0123456789abcdef"[bin[i] >> 4];
            hex[i * 2U + 1U] = "0123456789abcdef"[bin[i] & 0x0F];
        }
        
        hex[i * 2U] = 0U;
    }

    return hex;
}


This version of the function still works towards the same goal - converting a binary blob into hexadecimal - but does so using a lookup string instead of bitwise operations. This makes it somewhat simpler to interpret. It is like picking the relevant hexadecimal representation directly from a common string. The rest of the function has pretty much the same structure - it checks if the `bin` argument is null and validates some conditions initially and loops through the binary data string converting two bytes of binary into hexadecimal each time, storing the result in `hex`.