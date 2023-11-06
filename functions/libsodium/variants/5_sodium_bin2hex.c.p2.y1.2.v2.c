sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len) 
{ 
    if (bin_len > hex_maxlen / 2) 
    {
        sodium_misuse(); 
    }
  
    for (int i = 0; i < bin_len; i++) 
    {
        hex[i * 2] =   "0123456789abcdef"[bin[i] >> 4];
        hex[i * 2 + 1] =  "0123456789abcdef"[bin[i] & 0x0F];
    }

    hex[bin_len * 2] = '\0';

    return hex;
}