1. One possible variation is to use the more universally used version of hex conversion sequence, which use lookups in ASCII table values '0'...'9', 'a'...'f': 


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    static const char hex_chars[] = "0123456789abcdef";
    size_t i;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }
    for (i = 0; i < bin_len; i++)
    {
        hex[i * 2] = hex_chars[(bin[i] & 0xF0) >> 4];
        hex[i * 2 + 1] = hex_chars[(bin[i] & 0x0F)];
    }
    hex[i * 2] = '\0';

    return hex;
}

2. Another variant can be constructed by simplifying the calculations for `hex` array assignments:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    int high, low;
    
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }
    for(i = 0; i < bin_len; i++)
    {
        high = bin[i] >> 4;
        low = bin[i] & 0xf;
        hex[i * 2] = high + (high > 9 ? 87 : 48);
        hex[i * 2 + 1] = low + (low > 9 ? 87 : 48);
    }
    hex[i * 2] = '\0';

    return hex;
}


Note: 
  - The constant value '87' in function is used because it's the decimal ASCII value of character 'w'. Another constant, 'a' (or 'A') or '10' could be used, depending upon exact hexadecimal display requirement. That example replaced it with universal method using the ASCII '0', ..., '9', 'a', ..., 'f' or 'A', ..., 'F'.
  - The constant value '48' is the ASCII decimal value for character '0'. It would translate to hexadecimal characters being between '0', ..., '9' if the character value 'high' or 'low' are between 0, ..., 9. (48 + 0 = '0', 48 + 1 = '1', ..., 48 + 9 = '9'). If the 'high' or 'low' character values are above 9 (10, ..., 15), then they should translate to 'a', ..., 'f'.
