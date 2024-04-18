char *
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2  || hex_maxlen <= bin_len * 2)
        sodium_misuse();

    for (size_t i = 0; i < bin_len; i++)
    {
        int lower_bits = bin[i] & 0xf; 
        int upper_bits = bin[i] >> 4;
             
        unsigned int x = (unsigned char)(87U + upper_bits 
                          + (((upper_bits - 10U) >> 8) & ~38U)) 
                          | (((unsigned char)(87U + lower_bits 
                          + (((lower_bits - 10U) >> 8) & ~38U))) << 8);

        hex[i * 2U] = (char)(x >> 8);
        hex[i * 2U + 1U] = (char)x;
    } 

    hex[bin_len * 2U] = '\0';

    return hex;
}
