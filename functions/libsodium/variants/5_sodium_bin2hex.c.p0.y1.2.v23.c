Here's a renewed implementation of the provided function. The prior function utilised a few complex bitwise operator usages, which were simplified here for clarity, while bearing the same functionality.


char *sodium_bin2hex(char *hex, size_t hex_maxlen,
                     const unsigned char *bin, size_t bin_len)
{
    size_t i;

    if (bin_len >= SIZE_MAX/2 || hex_maxlen <= bin_len*2U)
    { 
        sodium_misuse();
    }
    for (i = 0U; i < bin_len; ++i)
    {
        int upper_digit = bin[i] >> 4;
        int lower_digit = bin[i] & 0x0f;

        upper_digit += '0';  // convert to character, on assumption that they're hex digits
        if (upper_digit > '9')
            upper_digit += 39;  // adjust from digit to letter a-f

        lower_digit += '0';  
        if (lower_digit > '9')
            lower_digit += 39;

        hex[i * 2] = (char) upper_digit;
        hex[i * 2 + 1] = (char) lower_digit;
    }
    hex[i * 2] = '\0';

    return hex;
}
