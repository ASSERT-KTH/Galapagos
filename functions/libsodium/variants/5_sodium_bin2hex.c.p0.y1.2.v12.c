char *sodium_bin2hex(char *hex, const size_t hex_maxlen, const unsigned char *bin, const size_t bin_len) 
{
    size_t i;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    
    for (i = 0; i < bin_len; i++) 
    {
        int upper = bin[i] >> 4;
        int lower = bin[i] & 0xf;
        hex[i * 2U] = (char)((upper < 10) ? upper + '0' : upper + 'a' - 10);
        hex[i * 2U + 1U] = (char)((lower < 10) ? lower + '0' : lower + 'a' - 10);
    }
    
    hex[i * 2U] = 0U;
    
    return hex;
}