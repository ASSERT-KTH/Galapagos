1) Releasing intermediate variables immediately after use


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) {
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    int ret = 0;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        unsigned char c = (unsigned char) hex[hex_pos];
        unsigned char c_num = c ^ 48U;
        unsigned char c_num0 = (c_num - 10U) >> 8;
        unsigned char c_alpha = (c & ~32U) - 55U;
        unsigned char c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }
        unsigned char c_acc;
        unsigned char c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
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
        hex_pos++;
    }
    if (state != 0U) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }
    if (ret != 0) {
        bin_pos = 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    return ret;
}


2) Removing assignments to intermediate constants that are not necessary


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) {
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    int ret = 0;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        unsigned char c =  hex[hex_pos];
        if (((c ^ 48U - 10U) >> 8 | ( (c & ~32U) -  55U - 10U) ^ ( (c & ~32U) -  55U  - 16U) >> 8) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }
        unsigned char c_val = (( (c ^ 48U) - 10) >> 8 & ( c ^ 48U) ) | (( ( (c & ~32U)- 55U - 10) ^ (c & ~32U - 55U - 16) >> 8) & ((c & ~32U) - 55U) );
        if (bin_pos >= bin_maxlen) {
            ret = -1;
            errno = ERANGE;
            break;
        }
        if (state == 0U) {
           unsigned char c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_val | c_val;
        }
        state = ~state;
        hex_pos++;
    }
    if (state != 0U) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }
    if (ret != 0) {
        bin_pos = 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    return ret;
}


3) Merging condition hierarchy 


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) {
    size_t bin_pos = (size_t) 0U;
    size_t hex_pos = (size_t) 0U;
    int ret = 0;
    unsigned char state = 0U;

    while(1){
        if(hex_pos >= hex_len) break;
        unsigned char c = (unsigned char)hex[hex_pos];
        unsigned char c_num0 = (c ^48U -10 >>8;
        unsigned char c_alpha0 = (((c & ~32)- 55U - 10) ^ ((c & ~32U) - 55U - 16)) >> 8;
        if (c_num0 | c_alpha0){
            if(ignore && !state && strchr(ignore,c)){
                hex_pos++;
                continue;
            }
            break;
        }
        uint8_t cv = (c_num0 *)(
    }
