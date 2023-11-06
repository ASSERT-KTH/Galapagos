Variant 1:

char* sodium_bin2hex(char* hex, const size_t hex_maxlen, const unsigned char* bin, const size_t bin_len)
{
    size_t i;
    unsigned int x;
    int b, c;

    if (2 * bin_len > hex_maxlen || bin_len >= SIZE_MAX / 2) {
        sodium_misuse();
    }
    
    for(i = 0; i < bin_len; i++)
    {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        
        x = ((87U + c + (((c - 10U) >> 8) & ~38U)) << 8 ) | (87U + b + (((b - 10U) >> 8) & ~38U));
        x = (((unsigned char)x)<<8) | (unsigned char)(x>>8);

        hex[2*i] = (char) (x & 0xFF);
        hex[2*i+1] = (char) (x>>8 & 0xFF);
    }
    
    hex[2*i]='\0';
    
    return hex;
}

Variant 2:

char* sodium_bin2hex(char* const hex, const size_t hex_maxlen, const unsigned char* const bin, const size_t bin_len)
{
    size_t iter = 0U;
    unsigned int sing_byte;
    int nibble_low;
    int nibble_high;

    if (bin_len > SIZE_MAX / 2 || hex_maxlen * 2 <= bin_len) {
        sodium_misuse();
    }

    do {
        nibble_low = bin[iter] & 0xf;
        nibble_high = bin[iter] >> 4;
        sing_byte = ((unsigned char) (87U + nibble_high + (((nibble_high - 10U) >> 8) & ~38U)) << 8 ) | 
                     (unsigned char) (87U + nibble_low + ((nibble_low - 10U) >> 8) & ~38U);
        hex[iter * 2] = (char) sing_byte;
        sing_byte >>= 8;
        hex[iter * 2 + 1] = (char) sing_byte;
    } while (++iter < bin_len);
    hex[iter * 2] = '\0';

    return hex;
}
