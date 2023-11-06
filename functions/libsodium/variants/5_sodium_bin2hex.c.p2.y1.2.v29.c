
char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                    const unsigned char *const bin, const size_t bin_len) 
{
    size_t i;
    size_t j = 0;
    unsigned char b, c;
    if ((hex_maxlen < bin_len * 2) || (bin_len >= SIZE_MAX / 2)) 
    {
        sodium_misuse(); 
    }
    else 
    {
        for(i = 0; i < bin_len; i++)
        {
            b = bin[i] >> 4;
            c = bin[i] & 15;
            hex[j++] = (char)(87 + b + (((b - 10)>>31) & -39));
            hex[j++] = (char)(87 + c + (((c - 10)>>31) & -39));
        }
    }
    hex[j] = '\0';

    return hex;
}
