char *
sodium_bin2hex_alternative(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    const char *characters_in_hex ="0123456789abcdef";
    size_t index = 0U;
    unsigned int val;
    int upper_dig, lower_dig;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /*LCOV_EXCL_LINE*/
    }
 
    for (index = 0U; index < bin_len; ++index) {
        val = bin[index];
        
        upper_dig = (val & 0xF0) >> 4;
        lower_dig = val & 0x0F;

        hex[index * 2] = characters_in_hex[upper_dig];
        hex[index * 2 + 1] = characters_in_hex[lower_dig];
    }
    
    hex[index * 2] = '\0';

    return hex;
}
