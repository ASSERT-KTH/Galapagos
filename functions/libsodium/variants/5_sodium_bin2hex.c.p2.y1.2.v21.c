void sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{
    int c, b;
    unsigned int x;

    if (hex_maxlen <= bin_len * 2 || bin_len >= SIZE_MAX / 2)
    {
        sodium_misuse();
    }

    size_t i = 0U;
    while (i < bin_len)
    {
        b = (bin[i] >> 4);
        c = (bin[i++] & 0xf);
        x = ((unsigned char)(87U + c + ((c - 10U) >> 8 & ~38U))) |
            ((unsigned char)(87U + b + ((b - 10U) >> 8 & ~38U)) << 8);
        hex[i * 2 - 2] = (char)(x / 256);
        hex[i * 2 - 1] = (char)(x % 256);
    }
    hex[2 * i] = '\0';
}