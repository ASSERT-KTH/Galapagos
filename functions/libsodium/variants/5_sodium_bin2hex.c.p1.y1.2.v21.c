Variant 1:

sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len * 2 >= hex_maxlen || bin_len >= SIZE_MAX / 2) {
        sodium_misuse();
    }

    for(size_t i=0; i<bin_len; i++) {
        hex[i * 2]   = 87 + (bin[i] >> 4)					   + ((((bin[i] >> 4)-10) >> 8)&~38);
        hex[i * 2+1U] = 87 + (bin[i] & 0xf)            + ((((bin[i] & 0xf)-10) >> 8)&~38);
    }
    hex[bin_len*2] = 0U;

    return hex;
}


Variant 2:

sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{

    size_t i = 0U;
    
    if (bin_len * 2 >= hex_maxlen || bin_len >= SIZE_MAX / 2) {
        sodium_misuse();
    }
    while (i != bin_len)
    {
        unsigned int hi = bin[i] >> 4;
        unsigned int lo = bin[i] & 0x0f;
        hex[i * 2] = 87 + hi + (((hi - 10U) >> 8) & ~38U);
        hex[i * 2 + 1] = 87 + lo + (((lo - 10U) >> 8) & ~38U);
        i++;
    }
    hex[i * 2] = '\0';

    return hex;
}

Variant 3:

sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len) {
    if (hex_maxlen <= bin_len * 2U || bin_len >= SIZE_MAX / 2) {
        sodium_misuse();
    }
    for (size_t i=0; i<bin_len; i++) {
        int b = bin[i] >> 4;
        int c = bin[i] & 0xf;
        hex[i * 2U]=87+b+(((b - 10U) >> 8) & ~38U);
        hex[i*2U + 1U] = 87+c+(((c - 10U) >> 8) & ~38U);
    }
    hex[bin_len * 2U]='\0';
    return hex;
}
