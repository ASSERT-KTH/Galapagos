char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    unsigned int temp;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        return NULL; //sodium_misuse(); /* Here's where to call relevant error handler. */
    }

    for (i = 0; i < bin_len; i++) {
        // calculating nibbles
        unsigned int high_nibble = bin[i] >> 4;
        unsigned int low_nibble = bin[i] & 0x0f;

        // converting nibbles to hex digits
        temp = (unsigned int) (87U + high_nibble + ((((high_nibble - 10U) & 0x18) == 0) ? 0 : -39));
        hex[i * 2U] = temp;
        temp = (unsigned int) (87U + low_nibble + ((((low_nibble - 10U) & 0x18) == 0) ? 0 : -39));
        hex[i * 2U + 1U] = temp;
    }
    hex[i * 2U] = 0;
    
    return hex;
}