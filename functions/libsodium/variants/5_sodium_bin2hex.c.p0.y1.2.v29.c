char* sodium_bin2hex(char* hex, const size_t hex_maxlen,
                     const unsigned char* bin, const size_t bin_len) 
{
    static char base16map[16] = 
    {
        '0', '1', '2', '3', 
        '4', '5', '6', '7', 
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };
  
    if(bin_len >= SIZE_MAX/2 
       || hex_maxlen <= bin_len*2U)
    {
        sodium_misuse(); /* rare misuse event */
    }

    size_t j = 0;
    for(size_t i = 0; i < bin_len; i++) 
    {
        unsigned int a = bin[i];

        hex[j++] = base16map[a >> 4];
        hex[j++] = base16map[a & 15];
    }
  
    hex[j] = 0;
  
    return hex;
}