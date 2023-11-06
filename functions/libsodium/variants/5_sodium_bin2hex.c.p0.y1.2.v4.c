char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
    size_t i = 0;
    unsigned int temp;
    for (; i < bin_len; i++) {
        if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2) {
            sodium_misuse(); // Performance misuse
        }
        int lowNybble = bin[i] & 0xf;
        int highNybble = bin[i] >> 4;
        temp = (unsigned int) ((lowNybble <= 9 ? lowNybble + '0' : lowNybble - 10 + 'a')) |
               (unsigned int) ((highNybble <= 9 ? highNybble + '0' : highNybble - 10 + 'a')) << 8;
        hex[i * 2] = temp >> 8;
        hex[i * 2 + 1] = temp & 0xff;
    }
    hex[i * 2] = 0;
    return hex;
}