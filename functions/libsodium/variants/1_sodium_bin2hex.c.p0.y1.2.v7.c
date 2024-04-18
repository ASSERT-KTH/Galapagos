char *
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }    

    for (size_t i = 0; i < bin_len; i++) {
        unsigned int hiNibble = bin[i] >> 4;
        unsigned int loNibble = bin[i] & 0xf;
        hex[i * 2U]     = (char) ((hiNibble < 10) ? hiNibble + '0' : hiNibble - 10 + 'a');
        hex[i * 2U + 1] = (char) ((loNibble < 10) ? loNibble + '0' : loNibble - 10 + 'a');
    }
  
    hex[bin_len * 2U] = '\0';
    return hex;
}

