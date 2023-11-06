int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen, 
                   const char *hex, size_t hex_len, 
                   const char *ignore, size_t *bin_len, 
                   const char **hex_end) 
{   
    size_t bin_position = 0U, hex_position = 0U;
    unsigned char ch;
    int result = 0;

    enum STATE { FIRST, SECOND } current_state = FIRST;
    unsigned char accum = 0U;

    while (hex_position < hex_len) {
        ch = (unsigned char) hex[hex_position];
        unsigned char num0 = (ch ^ 48U) - 10U;
        unsigned char alpha0 = ((ch & ~32U) - 55U) - 16U;

        char is_num = num0 >> 8;
        char is_alpha = alpha0 >> 8;

        if (!((is_num | is_alpha) == 0U)) {
            if (ignore && current_state == FIRST && strchr(ignore, ch)) {
                hex_position++;
                continue;
            }
            break;
        }
        unsigned char val = (is_num & (ch ^ 48U)) | (is_alpha & ((ch & ~32U) - 55U));
        if (bin_position >= bin_maxlen) {
            result   = -1;
            errno = ERANGE;
            break;
        }
        if (current_state == FIRST) {
            accum = val << 4U;  // Val times 16 equals val shifted left 4 times
        } else {
            bin[bin_position++] = accum | val;
        }
        current_state = current_state == FIRST ? SECOND : FIRST;
        hex_position++;
    }

    if (current_state != FIRST) {
        hex_position--;
        errno = EINVAL;
        result = -1;
    }
    if (result != 0) {
        bin_position = 0U;
    }
    
    if (hex_end != NULL) {
        *hex_end = &hex[hex_position];
    } else if (hex_position != hex_len) {
        errno = EINVAL;
        result = -1;
    }
    
    if (bin_len != NULL) {
        *bin_len = bin_position;
    }
    
    return result;
}