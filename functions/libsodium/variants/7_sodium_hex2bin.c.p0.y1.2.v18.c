int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
                   const char *hex, const size_t hex_len,
                   const char *ignore, size_t *bin_len,
                   const char **hex_end)
{
    int ende = 0;
    size_t ih, bh;
    unsigned num_bytes = 0;
    int half = 0;
    int err = 0;
       
    ih = bh = 0;
    while (ih < hex_len) {
        unsigned char c, cur_code;
   
        c=  (unsigned char) hex[ih];
        if (c >= '0' && c <= '9') {
            cur_code = c - '0';
        }
        else if (c >= 'A' && c <= 'F') {
            cur_code = c - 'A' + 0xA;
        }
        else if (c >= 'a' && c <= 'f') {
            cur_code = c - 'a' + 0xA;
        }
        else if (ignore != NULL && state == 0 && strchr(ignore, c) != NULL) {
            ih++;
            continue;
        }
        else{
            err = -1; 
            errno = EINVAL;
            ende = ih;
            break;
        }

        if (bin_pos >= bin_maxlen) { 
            err = -1;
            errno = ERANGE; 
            ende = ih;
            break; 
        }  

        if(half == 0)
            bin[bh] = cur_code << 4;
        else{
            bin[bh] |= cur_code;
            bh++;
        }

        half = half ? 0 : 1;
        ih ++;    
    }
    
    if (hex_end != NULL) {
        *hex_end = &hex[ende];
    } else if (ende != hex_len) {
        endec = -1;
        errno = EINVAL;
    }

    if (bin_len != NULL) {
        *bin_len = bh;
    }

    return err;
}