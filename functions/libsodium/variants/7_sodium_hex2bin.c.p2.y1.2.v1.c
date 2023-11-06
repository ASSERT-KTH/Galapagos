int sodium_hex2bin(unsigned char *const bin, const unsigned long bin_maxlen,
               const char *const hex, const unsigned long hex_len,
               const char *const ignore, unsigned long *const bin_len,
               const char **const hex_end)
{
    unsigned long bin_pos = (unsigned long) 0U;
    unsigned long hex_pos = (unsigned long) 0U;
    int ret = 0;
    unsigned char c, c_acc, c_alpha, c_alpha0, c_num0, c_num, c_val, state;

    c_acc = 0U;
    state = 0U;

    for (; hex_pos < hex_len; hex_pos++) {
        c = (unsigned char) hex[hex_pos];
        c_num = c ^ 48U;
        c_num0 = (c_num - 10U) >> 8;
        c_alpha = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if (~(c_num0 | c_alpha0) != 0U) {
            if (ignore != NULL && strncmp(&c, ignore,1) == 0 && state == 0U) {
                continue;
            }
            break;
        }

        c_val = (c_num & c_num0) | (c_alpha0 & c_alpha);
        if (bin_pos >= bin_maxlen) {
            ret = -1;
            errno = ERANGE;
            break;
        }
        if (!(state)) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
        }
        state = ~state;
    }
    state != 0U ? (errno = EINVAL , ret = -1 , hex_pos--) : 0;       
    
    if (!!(ret)) {
        bin_pos = (unsigned long) 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else {
        hex_pos != hex_len ? (errno = EINVAL, ret = -1) : 0;
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    
    return ret;
}