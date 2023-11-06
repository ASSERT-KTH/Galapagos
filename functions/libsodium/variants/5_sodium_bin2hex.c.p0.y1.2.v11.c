char* sodium_bin2hex(char *const hex, const size_t hex_maxlen, 
  const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) 
    {
        sodium_misuse();
    }

    for (size_t i = 0; i < bin_len; i++) 
    {
        hex[i * 2] = "0123456789abcdef"[bin[i] >> 4];
        hex[i * 2 + 1] = "0123456789abcdef"[bin[i] & 0xF];
    }
    hex[bin_len * 2] = 0U;

    return hex;
}