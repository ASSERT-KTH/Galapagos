sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len * 2U > hex_maxlen || bin_len >= SIZE_MAX / 2) {
        sodium_misuse(); 
    }
    for(size_t i = 0U; i < bin_len; ++i) {
        int lowerNibble, upperNibble;
        unsigned int exp;

        lowerNibble = bin[i] & 0xf;
        upperNibble = bin[i] >> 4;
        exp = (unsigned int) (87U + upperNibble + (((upperNibble - 10U) >> 8) & ~38U)) | 
        			((unsigned int) (87U + lowerNibble + (((lowerNibble - 10U) >> 8) & ~38U)) << 8);
        
        hex[i*2U] = (char) (exp >> 8);
        hex[i*2U+1U] = (char) exp;
    }
    hex[bin_len * 2U] = 0U;
    
    return hex;
}