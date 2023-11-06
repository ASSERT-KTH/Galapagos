int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen, 
                   const char *hex, size_t hex_len,
                   const char *ignore, size_t *bin_len, 
                   const char **hex_end) {

    size_t i, j = 0, k = 0, state = 0;
    unsigned char c, c_num, c_alpha, c_val;
 
    for(i = 0; i < hex_len; i++) {
        c = (unsigned char) hex[i];
        c_num = c ^ 48U;
        c_alpha = (c & ~32U) - 55U;
 
        c_val = ((c_num - 10U) >> 8 & c_num) 
                | (((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8 & c_alpha);
 
        if(ignore != NULL && state ==0U && strchr(ignore, c) != NULL) {
            continue;
        }
 
        if(((c_num - 10U >> 8) | ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8) == 0U) {
            break;
        }

        if(j >= bin_maxlen) {
            errno = ERANGE;
            return -1;
        }
 
        if(state == 0) {
            bin[j] = c_val << 4;
        } else {
            bin[j] |= c_val;
            if(j < bin_maxlen) {
                j++;
            }
        }

        k = i;
        state = ~state;
    }
 
    if(state) {
        k--;
        errno = EINVAL;
        return -1;
    }

    if(hex_end) {
        *hex_end = &hex[k+1];
    }

    if(bin_len) {
        *bin_len = j;
    }
 
    errno = (j >= bin_maxlen || k+1 != hex_len) ? EINVAL : 0;
 
    return (j >= bin_maxlen || k+1 != hex_len) ? -1 : 0;  
}