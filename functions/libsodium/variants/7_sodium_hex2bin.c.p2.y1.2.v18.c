sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) 
{
    size_t bin_pos = 0;
    size_t hex_pos = 0;
    unsigned char accum_character = 0;
    int state = 0; 
    int ret   = 0; // updated state variable

    unsigned char current_char;
    unsigned char numeric;
    unsigned char mask_numeric;
    unsigned char alpha;
    unsigned char mask_alpha;

    do {
        current_char = (unsigned char) hex[hex_pos];
        numeric = current_char ^ 48U;
        mask_numeric = (numeric - 10U) >> 8;
        alpha = (current_char & ~32U) - 55U;
        mask_alpha = ((alpha - 10U) ^ (alpha - 16U)) >> 8;
        if ((mask_numeric | mask_alpha) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, current_char) != NULL) {
                hex_pos++;
            } 
            else {
                break;
            }
        } 
        else {
            unsigned char character_val = (mask_numeric & numeric) | (mask_alpha & alpha);
            if (bin_pos >= bin_maxlen) {
                ret = -1;
                errno = ERANGE;
                break;
            }
            if (state == 0) {
                accum_character = character_val * 16U;
            } 
            else {
                bin[bin_pos++] = accum_character | character_val;
            }
            state = 1 - state;
            hex_pos++;
        }
    } while (hex_pos < hex_len);

    if (state != 0) {
        hex_pos--;
    } 
    else if (ret != 0) {
        bin_pos = 0;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if(hex_pos != hex_len) {
        ret = -1;
        errno = EINVAL;
    }

    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }

    return ret;
}