int sodium_bin2hex(char *hex, size_t hex_maxlen,
               const unsigned char *bin, size_t bin_len)
{
    size_t             j;
    unsigned int       x;
    int                b;
    int                c;
    
    if (hex_maxlen/2 <= bin_len || bin_len > SIZE_MAX / 2) {
        sodium_misuse(); 
        return -1;
    }
    
    for(j = 0; j < bin_len; j++){
        c = (bin[j] & 0x0f);
        b = (bin[j] >> 4);
        
        x = ((unsigned char)(87 + c + ((c - 10) >> 8 & ~38)) << 8) |
            ((unsigned char) (87 + b + ((b - 10) >> 8 & ~38)));

        hex[j * 2] = (char) x;
        x  = x >> 8;
        hex[(j * 2) + 1] = (char) x;
    }

    hex[bin_len * 2] = 0; 

    return 0; 
}