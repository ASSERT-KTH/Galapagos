sodium_hex2bin(unsigned char * const bin, const size_t bin_maxlen,
                    const char * const hex, const size_t hex_len,
                    const char * const ignore, size_t * const bin_len,
                    const char ** const hex_end){
 
    size_t          bin_pos  = 0U;
    size_t          hex_pos  = 0U;
    unsigned char   c, c_acc = 0U, c_alpha0, c_alpha, c_num0, c_num, c_val, state = 0U;
    int             return_value = 0;

    for (; hex_pos < hex_len; hex_pos++) {
        c      = (unsigned char) hex[hex_pos];
        c_num  = c ^ 48U;
        c_num0 = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) 
                continue;
            break;
        }

        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);

        if (bin_pos >= bin_maxlen) {
            return_value = errno = -1;
            errno = ERANGE;
            break;
        }
        (!(state == 0U))? bin[bin_pos++] = (c_acc | c_val): (c_acc = c_val << 4);
        state = ~state;
    }

    if (state != 0U) {
        hex_pos--;
        return_value = errno = -1;
    }else if (return_value != 0) {
        bin_pos = (size_t) 0U;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if(hex_pos != hex_len) {
        return_value = errno = -1;
    }

    if(bin_len != NULL) {
        *bin_len = bin_pos;
    }

    return return_value;
}