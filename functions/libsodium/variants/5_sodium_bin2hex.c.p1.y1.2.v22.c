Variant 1:

char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();  
    }
    for(i = 0; i < bin_len; i++)
    {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned)(87 + c + (((c - 10) >> 8) & ~38)) << 8 | (unsigned)(87 + b + (((b - 10) >> 8) & ~38));
        hex[i * 2] = (char) x;
        x >>= 8;
        hex[i * 2 + 1] = (char) x;
    }
    hex[i * 2] = 0;
    return hex;
}

Variant 2:

char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    unsigned int x;
    int          b;
    int          c;

    if (bin_len * 2 >= hex_maxlen || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();  
    }
    for(size_t i = 0; i < bin_len;)
    {
        b = bin[i] >> 4;
        c = bin[i++] & 0xf;
        x = (unsigned)(87 + c + (((c - 10) >> 8) & ~38)) << 8 | (unsigned)(87 + b + (((b - 10) >> 8) & ~38));
        hex[i * 2 - 2] = (char) x;
        hex[i * 2 - 1] = (char)(x >> 8);
    }
    hex[bin_len * 2] = 0;
    return hex;
}

Note: Variants given are mostly equivalent, only loop and equivalence form are changed, all preserving the original logic. They are meant to show how you can modify C code while keeping its functionality.