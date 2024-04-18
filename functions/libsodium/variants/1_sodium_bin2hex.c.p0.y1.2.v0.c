char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) 
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) 
    {
        sodium_misuse(); 
    }

    for(size_t i = 0U; i < bin_len; ++i)
    {
        sprintf(hex + (i*2U), "%02x", bin[i]);
    }
    
    hex[bin_len*2U] = '\0';
    return hex;
}
