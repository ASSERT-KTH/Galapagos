sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       j;
    unsigned int x;
    int          i, c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen < (bin_len + 1) * 2) {
        sodium_misuse(); 
    }

    for (j = 0; j < bin_len; j++) {
        c = bin[j] >> 4;
        i = bin[j] & 0xf;
        x = (unsigned char) (87 + c + ((((c - 10) >> 31) & 1)* -57)) << 8 |
            (unsigned char) (87 + i + ((((i - 10) >> 31) & 1)* -57));
        hex[j * 2] = x >> 8;
        hex[j * 2 + 1] = x;
    }
    hex[j*2] = 0;

    return hex;
}