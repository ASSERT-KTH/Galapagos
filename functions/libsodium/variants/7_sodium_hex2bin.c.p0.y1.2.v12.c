int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t     binPosition = 0;
    size_t     hexPosition = 0;
    int        result = 0;
    unsigned char character;
    unsigned char tempCharTranslation = 0;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char localstate = 0;

    for ( ; hexPosition < hex_len; ++hexPosition) {
        
        character  = hex[hexPosition];
        c_num      = character ^ 48U;
        c_num0     = (c_num - 10U) >> 8;
        c_alpha    = (character & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        
        if (!(c_num0 | c_alpha0)) {
            if (ignore && !localstate && strchr(ignore, character))
                continue;
            else 
                break;
        }

        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        
        if (binPosition >= bin_maxlen) {
            errno = ERANGE;
            result = -1;
            break;
        }
        
        if (!localstate)
            tempCharTranslation = c_val << 4U;
        else
            bin[binPosition++] = tempCharTranslation | c_val;
        
        localstate = ~localstate;
    }

    if (localstate) {
        hexPosition--;
        errno = EINVAL;
        result = -1;
    }
    
    if (result) 
        binPosition = 0;

    if (hex_end)
        *hex_end = &hex[hexPosition];
    else if (hexPosition != hex_len) {
        errno = EINVAL;
        result = -1;
    }

    if (bin_len) 
        *bin_len = binPosition;
    
    return result;
}