Variant 1:

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{
    size_t       i = 0;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2) {
        sodium_misuse();
    }
    
    for (i = 0; i < bin_len; ++i) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87 + c + (((c - 10) >> 8) & ~38)) << 8 |
            (unsigned char) (87 + b + (((b - 10) >> 8) & ~38));
        hex[i * 2] = (char) x;
        x >>= 8;
        hex[i * 2 + 1] = (char) x;

    }
    hex[i * 2] = 0;

    return hex;
}


Variant 2:

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    unsigned int x;
    int b, c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2) {
        sodium_misuse();
    }

    for (i = 0; i < bin_len; i++) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = ((unsigned char) (87 + c + (((c - 10) >> 8) & ~38)) << 8) |
            (unsigned char) (87 + b + (((b - 10) >> 8) & ~38));
        hex[i * 2] = x & 0xff;
        x >>= 8;
        hex[i * 2 + 1] = x & 0xff;
    }

    hex[i * 2] = '\0';

    return hex;
}

Variant 3:

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    unsigned int x;
    int highNibble, lowNibble;

    if (bin_len < SIZE_MAX / 2 || hex_maxlen > bin_len * 2) {
        for (i = 0; i < bin_len; i++) {
            lowNibble = bin[i] & 0xf;
    	    highNibble = bin[i] >> 4;
            x = ((unsigned char) (87 + highNibble + (((highNibble - 10) >> 8) & ~38)) << 8) |
                (unsigned char) (87 + lowNibble + (((lowNibble - 10) >> 8) & ~38));
            hex[i * 2] = x & 0xff;
            x >>= 8;
            hex[i * 2 + 1] = x & 0xff;
        }
        hex [i * 2] = '\0';
    } else {
        sodium_misuse();
    }

    return hex;
}
