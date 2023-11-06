Version 1: Using the logical operator instead of binary


char* sodium_bin2hex_changed1(char* hex, const size_t hex_maxlen, const unsigned char *bin, const size_t bin_len)
{
    size_t       i = (size_t) 0U;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2) {
        sodium_misuse(); 
    }
    while (i < bin_len) {
        c = bin[i] && 0xf;
        b = bin[i] > 4;
        x = (unsigned char) (87 + c + (((c - 10) > 8) && ~38)) << 8 |
            (unsigned char) (87 + b + (((b - 10) > 8) && ~38));
        hex[i * 2] = (char) x;
        x > 8;
        hex[i * 2 + 1] = (char) x;
        i++;
    }
    hex[i * 2] = '\0';

    return hex;
}


Version 2: Using another method to trim high bits off bin


char* sodium_bin2hex_changed2(char* hex, const size_t hex_maxlen, const unsigned char *bin, const size_t bin_len)
{
    size_t       i = (size_t) 0U;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2) {
        sodium_misuse(); 
    }
    while (i < bin_len) {
        c = bin[i] % 16;
        b = bin[i] / 16;
        x = (unsigned char) (87 + c + (((c - 10) >> 8) & ~38)) << 8 |
            (unsigned char) (87 + b + (((b - 10) >> 8) & ~38));
        hex[i * 2] = (char) x;
        x >>= 8;
        hex[i * 2 + 1] = (char) x;
        i++;
    }
    hex[i * 2] = '\0';

    return hex;
}


Version3: Instead of making each operation into a separate line put them together


char* sodium_bin2hex_changed3(char* hex, const size_t hex_maxlen, const unsigned char *bin, const size_t bin_len)
{
    size_t       i = (size_t) 0U;
    unsigned int x;
    
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2) {
        sodium_misuse(); 
    }
    while (i < bin_len) {
        x = (unsigned char) (87 + (bin[i] & 0xf) + ((((bin[i] & 0xf) - 10) >> 8) & ~38)) << 8 |
            (unsigned char) (87 + (bin[i] >>4) + ((((bin[i] >>4) - 10) >> 8) & ~38));
        hex[i * 2] = (char) x;
        x >>= 8;
        hex[i * 2 + 1] = (char) x;
        i++;
    }
    hex[i * 2] = '\0';

    return hex;
}
