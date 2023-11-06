
char *sodium_bin2hex_v1(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
	int          high;
    int          low;
    size_t       counter;
    unsigned int both;

    if (bin_len * 2 >= hex_maxlen || bin_len * 2 >= SIZE_MAX) {
        sodium_misuse(); 
    }
    
    for (counter = 0; counter < bin_len; ++counter) {
        low = bin[counter] & 0xF;
        high = bin[counter] >> 4;
        both  = (unsigned int) ((87 + low + (((low - 10) >> 8) & ~38)) << 8)
        	    | (87 + high + (((high - 10) >> 8) & ~38));
        
        hex[2 * counter] = (char) both;
        both >>= 8;
        hex[2 * counter + 1] = (char) both;
    }
    
    hex[2 * counter] = '\0';

    return hex;
}

char *sodium_bin2hex_v2(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    int          low;
    int          high;
    size_t       offset;

    if (hex_maxlen <= bin_len * 2 || 2 * bin_len >= SIZE_MAX) {
        sodium_misuse();
    }
    
    for (offset = 0; offset < bin_len; ++offset) {
        low = bin[offset] & 0xf;
        high = bin[offset] >> 4;
        unsigned int bothParts = (unsigned int) ((87 + low + (((low - 10) >> 8) & ~38)) << 8)
                                  | (87 + high + (((high - 10) >> 8) & ~38));
        
        hex[offset * 2] = (char) bothParts;
        bothParts >>= 8;
        hex[offset * 2 + 1] = (char) bothParts;
    }
    
    hex[offset * 2] = 0;

    return hex;
}
