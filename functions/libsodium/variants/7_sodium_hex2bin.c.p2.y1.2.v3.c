sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    int ret = 0;
    
    unsigned char c;
    unsigned char c_alpha;
    unsigned char c_alpha0;
    unsigned char c_num;
    unsigned char c_num0;
    unsigned char state;
    unsigned char c_val;
    unsigned char c_acc = 0U;

    for (hex_pos = 0; hex_pos < hex_len; hex_pos++){
        c = (unsigned char) hex[hex_pos];
        c_num = c ^ 48U;
        c_alpha = (c & ~32U) - 55U;
        c_num = (c_num - 10U) >> 8;
        c_num0 = c_num;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        
        if (((c_num0 | c_alpha0) == 0U) && state) {
            bin_pos++;
            continue;
        }

        if (bin_pos >= bin_maxlen) {
            ret = -1;
            errno = ERANGE;
            break;
        }

        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
       
        if (!state) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
        }
        
        state = ~state;
    }
    
    if (state) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }

    if (ret) {
        bin_pos = 0U;
    }
    
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }

    if (bin_len) {
        *bin_len = bin_pos;
    }
    
    return ret;
}