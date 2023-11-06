size_t sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
                      const char *hex, const size_t hex_len,
                      const char *ignore, size_t *bin_len,
                      const char **hex_end)
{
    size_t   bin_position=0, hex_position=0;
    int   result   = 0;
    unsigned char char_current, char_merged = 0;
    unsigned char char_alpha_detection, char_alpha;
    unsigned char char_numerical_detection, char_numerical;
    unsigned char char_value;
    unsigned char change_state_flag = 0;

    for (hex_position = 0; hex_position < hex_len; ++hex_position) {
        char_current       = (unsigned char) hex[hex_position];
        char_numerical     = char_current ^ 48U;
        char_numerical_detection = (char_numerical - 10U) >> 8;
        char_alpha         = (char_current & ~32U) - 55U;
        char_alpha_detection = ((char_alpha - 10U) ^ (char_alpha - 16U)) >> 8;
        
        if ((char_numerical_detection | char_alpha_detection)==0) {
            if (ignore != NULL && change_state_flag == 0 && strchr(ignore, char_current) != NULL) {
                continue;
            }
            break;
        }
        char_value = (char_numerical_detection & char_numerical) | (char_alpha_detection & char_alpha);
        
        if (bin_position>=bin_maxlen) {
            result   = -1;
            errno = ERANGE;
            break;
        }
        if (change_state_flag == 0) {
            char_merged = char_value << 4;
        } else {
            bin[bin_position++] = char_merged | char_value;
        }
        change_state_flag = ~change_state_flag;
        
    }
    if (change_state_flag != 0) {
        --hex_position;
        errno = EINVAL;
        result = -1;
    }
    if (result < 0) {
        bin_position=0;
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