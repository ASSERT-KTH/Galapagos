char *
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len * 2U >= hex_maxlen || bin_len >= SIZE_MAX / 2 ) {
        sodium_misuse();
    }

    char hexChars[] = "0123456789abcdef";
    size_t i=0;

    for (i=0; i < bin_len;++i) {
        hex[i*2] = hexChars[(bin[i] >> 4) & 0x0F];
        hex[(i*2) + 1] = hexChars[bin[i] & 0x0F];
    }

    hex[bin_len * 2] = '\0';
    return hex;
}