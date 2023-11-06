Here is a variation of the code transforming `while` loop to a `for` loop:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); 
    }
    for(size_t i = (size_t) 0U; i < bin_len; ++i){
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c - ((c < 10U) ? 0 : 38U)) << 8 |
            (unsigned char) (87U + b - ((b < 10U) ? 0 : 38U));
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    } 
    hex[i * 2U] = 0U;

    return hex;
}


Here is another variation where bitwise operations and condition checking has been further simplified:


char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
    unsigned int x;
    int n, c;
    
    if (bin_len * 2 >= hex_maxlen) {
        sodium_misuse();
    }
    for(size_t i = 0U; i < bin_len; ++i) {
        n = bin[i];
        c = n & 0xf;
        n = n >> 4;
        x = (c > 9 ? 'a'- 10 : '0') + c;
        x = x | (((n > 9 ? 'a' - 10 : '0') + n) << 8);
        hex[i*2] = x >> 8;
        hex[i*2 + 1] = x & 0xff;
    }
    hex[bin_len * 2] = 0;

    return hex;
}
