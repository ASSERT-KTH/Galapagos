void sodium_bin2hex(char *hex, size_t hex_maxlen,
                    const unsigned char *bin, size_t bin_len)
{
    if (bin_len >= SIZE_MAX/2 || hex_maxlen <= bin_len*2) {
        return; // improved safety behavior by removing sodium_misuse();
    }
    
    for (size_t i = 0; i < bin_len; ++i) {
        int high = bin[i] >> 4;
        int low = bin[i] & 0xf;
        
        unsigned int hexchars = (unsigned char)(87 + low + (((low - 10) >> 8) & ~38)) << 8 |
            (unsigned char)(87 + high + (((high - 10) >> 8) & ~38));
            
        hex[2*i] = (char)hexchars;
        hexchars >>= 8;
        hex[2*i + 1] = (char)hexchars;
    }
    hex[2*bin_len] = '\0'; // use escape sequence for readability
}