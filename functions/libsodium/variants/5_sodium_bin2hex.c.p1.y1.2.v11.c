Below are two variants of the original function:

Variant 1:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    unsigned int x;
    int b, c;

    if(2 * bin_len <= hex_maxlen && bin_len < SIZE_MAX / 2) {
        i = 0;
        do {
            c = bin[i] & 0xf;
            b = bin[i] >> 4;
            x = (unsigned int)((87 + c + ((0xFF & (c - 10)) & ~38)) << 8 |
                              (87 + b + ((0xFF & (b - 10)) & ~38)));
            x = x >> 8;
            hex[2 * i + 1] = (char) x;
            x = (unsigned int)((87 + c + ((0xFF & (c - 10)) & ~38)) << 8 |
                               (87 + b + ((0xFF & (b - 10)) & ~38)));
            hex[2 * i] = (char) x;
        } while (++i < bin_len);
        hex[2 * bin_len] = 0;
    } else {
        sodium_misuse();
    }
    
    return hex;
}


Variant 2:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    unsigned int x;
    int b, c;

    if(bin_len < SIZE_MAX / 2 && hex_maxlen > 2 * bin_len) {
        for(i = 0; i < bin_len; i++) {
            c = bin[i] & 0xf;
            b = bin[i] >> 4;

            x = ((unsigned int)(87U + c + (((c - 10U) >> 8) & ~38U)) << 8) |
                ((unsigned int)(87U + b + (((b - 10U) >> 8) & ~38U)));
            
            hex[2U * i] = (char) x;
            x >>= 8;
            hex[(2U * i) + 1U] = (char) x;
        }
        hex[2 * i] = '\0';
    } else {
        sodium_misuse();
    }

    return hex;
}
