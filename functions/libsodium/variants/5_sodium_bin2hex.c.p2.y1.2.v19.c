A slightly different version of original function is as follows. Differences include, the loop has been unrolled and casts of same type variables have been removed.

sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2)
        sodium_misuse();
  
    for (i = 0; i < bin_len; i++) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (87 + c + ((c - 10) >> 8 & ~38)) << 8 |
            (87 + b + ((b - 10) >> 8 & ~38));
        hex[i * 2] = x;
        x >>= 8;
        hex[i * 2 + 1] = x;
    }
  
    hex[2 * i] = '\0';

    return hex;
}