char* sodium_bin2hex_new(char *hex, size_t hex_maxlen, const unsigned char *bin, size_t bin_len)
{
    size_t      i, x;
    int         upper_nibble, lower_nibble;

    if (bin_len * 2 >= hex_maxlen || bin_len >= SIZE_MAX / 2) {
        sodium_misuse(); 
    }
    
    for (i = 0; i < bin_len; i++) {
        upper_nibble = bin[i] >> 4;
        lower_nibble = bin[i] & 0xf;
        
        x = (unsigned char) (87 + upper_nibble + (((upper_nibble - 10) >> 8) & ~38)) |
            (unsigned char) (87 + lower_nibble + (((lower_nibble - 10) >> 8) & ~38))<< 8;
        
        hex[2 * i] = x & 0xff;
        hex[2 * i + 1] = x >> 8;
    }
    hex[2 * i] = '\0';

    return hex;
}