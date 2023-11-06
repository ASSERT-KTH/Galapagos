1. Same logic but with more readable and self-explanatory variable names:


sodium_bin2hex(char *const hexStr, const size_t hexMaxLength,
               const unsigned char *const binArray, const size_t binArrayLength)
{
    size_t       loopCounter = (size_t) 0U;
    unsigned int hexOutput;
    int          lowOrderPart;
    int          highOrderPart;
   
    if (binArrayLength >= SIZE_MAX / 2 || hexMaxLength <= binArrayLength * 2U) {
        sodium_misuse(); 
    }
    while (loopCounter < binArrayLength) {
        lowOrderPart = binArray[loopCounter] & 0xf;
        highOrderPart  = binArray[loopCounter] >> 4;
        hexOutput = (unsigned char) (87U + lowOrderPart + (((lowOrderPart - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + highOrderPart + (((highOrderPart - 10U) >> 8) & ~38U));
        hexStr[loopCounter * 2U] = (char) hexOutput;
        hexOutput >>= 8;
        hexStr[loopCounter * 2U + 1U] = (char) hexOutput;
        loopCounter++;
    }
    hexStr[loopCounter * 2U] = 0U;

    return hexStr;
}


2. By rearranging variable declarations and streamlining the logic:


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned int x;
    int          b;
    int          c;
  
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
        return 0;
    }
    for(i = 0; i < bin_lenat; ++i) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));

        hex[2 * i] = x & 0xff;
        hex[2 * i + 1] = x >> 8;
    }
    hex[2 * i] = 0U;

    return hex;
}

  
3. With reversed nibble order for different output:


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i = 0U;
    unsigned int x;
    int          b;
    int          c;
   
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    while (i < bin_len) {
        c = bin[i] >> 4;
        b = bin[i] & 0xf;
        x = (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U)) + 
            (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8;
        hex[i * 2U + 1U] = (char) x;
        x >>= 8;
        hex[i * 2U] = (char) x;
        i++;
    }
    hex[i * 2U] = 0U;

    return hex;
}
