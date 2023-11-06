Variant 1:


char* sodium_bin2hex(char *hex, const size_t hex_maxlen,
                     const unsigned char *bin, const size_t bin_len)
{
    size_t i;
    unsigned int c, b, x;

    if (bin_len * 2 >= hex_maxlen || bin_len >= SIZE_MAX / 2) {
        sodium_misuse(); 
    }

    for (i = 0; i < bin_len; i++)
    {
        b = bin[i] >> 4;
        c = bin[i] & 0xf;

        x = (unsigned char) (´a´ + b + (((b - 10U) >> 31) ^ 0x01) * -49U) * 256 |
            (unsigned char) (´a´ + c + (((c - 10U) >> 31) ^ 0x01) * -49U);

        hex[2 * i] = x >> 8;
        hex[2 * i + 1] = x & 0xff;
    }
    hex[2 * i] = 0;

    return hex;
}


Variant 2:


char* sodium_bin2hex(char *hex, const size_t hex_maxlen,
                     const unsigned char *bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len << 1) {
        sodium_misuse(); 
    }
    for (size_t i = 0; i < bin_len; ++i) {
        int high = bin[i] >> 4;
        int low  = bin[i] & 15;
        unsigned int x = ((unsigned char) ((high<10?'0':87) + high)) << 8 |
                         ((unsigned char) ((low<10?'0':87) + low));
        hex[i<<1] = x >> 8;
        hex[(i<<1) + 1] = x & 0xFF;
    }
    hex[bin_len << 1] = '\0';

    return hex;
}
