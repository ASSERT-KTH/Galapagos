sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        hex_pos = (size_t) 0U;
    size_t        bin_pos = (size_t) 0U;
    unsigned char c;
    unsigned char c_val;
    unsigned char c_acc = 0U;
    int           ret     = 0;
    unsigned char state = 0U;

    for (; hex_pos < hex_len; hex_pos++) {
        c        = (unsigned char) hex[hex_pos];
        unsigned char c_num    = c ^ 48U;
        unsigned char c_num0   = (c_num - 10U) >> 8;
        unsigned char c_alpha  = (c & ~32U) - 55U;
        unsigned char c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                continue;
            }
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos < bin_maxlen) {
            if (state == 0U) {
                c_acc = c_val * 16U;
            } else {
                bin[bin_pos++] = c_acc | c_val;
            }
            state = ~state;
        } else {
            errno = ERANGE;
            ret = -1;
            break;
        }
    }
    if (state && !(ret == -1)) {
        errno = EINVAL;
        ret = -1;
        hex_pos--;
    }
    if (ret != 0) {
        while(bin_pos>0U){
            bin[bin_pos--]='\0';
        }
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    }
    else if (hex_pos < hex_len-1) {
        errno = EINVAL;
        return-1;
    }
    if (bin_len)
        *bin_len = bin_pos;
    else
        *bin_len=-1;
        
    return ret;
}