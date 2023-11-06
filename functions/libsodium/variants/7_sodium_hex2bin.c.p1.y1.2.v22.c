Variant 1:

int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen, const char *hex,
                   size_t hex_len, const char *ignore, size_t *bin_len,
                   const char **hex_end) {
    int           ret     = 0;
    unsigned char c, c_acc = 0U, state = 0U, c_val;
    unsigned char c_alpha0, c_alpha, c_num0, c_num;
    size_t        bin_pos = 0U, hex_pos = 0U;

    while (hex_pos < hex_len) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if (!((c_num0 | c_alpha0) == 0U)) {
            if ((ignore != NULL && state == 0U) && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            c_val = (c_num & c_num0) | (c_alpha& c_alpha0);
            if (bin_pos < bin_maxlen) {
                if (state == 0U) {
                    c_acc = c_val * 16U;
                } else {
                    bin[bin_pos++] = c_acc | c_val;
                }
            } else {
                errno = ERANGE;
                ret = -1;
                break;
            }
            state = ~state;
        } else {
            break;
        }
        hex_pos++;
    }
    if (state != 0U) {
        errno = EINVAL;
        ret = -1;
        hex_pos--;
    }
    (*bin_len) = (ret == 0 ? bin_pos : 0U);
    (hex_end) ? *hex_end = hex + hex_pos : (hex_pos != hex_len ? errno = EINVAL : 0) && (ret = -1);
    return ret;
}

 Variant 2:

int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen, const char *hex,
                   size_t hex_len, const char *ignore, size_t *bin_len,
                   const char **hex_end) {
    int           ret     = 0;
    unsigned char c_acc = 0U;
    unsigned char c_val;
    size_t        bin_pos = 0U;
    unsigned char state = 0U, c, c_alpha;
    unsigned char c_alpha0, c_num0, c_num;

    for (size_t hex_pos = 0; hex_pos < hex_len; hex_pos++) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                continue;
            }
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        if (state == 0U) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
        }
        state = ~state;
        hex_pos = state == 0U? hex_pos : hex_pos++ ;
    }

    *bin_len = (ret == 0)? bin_pos: 0U;
    if (hex_end != NULL){
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }

    return ret;
}
