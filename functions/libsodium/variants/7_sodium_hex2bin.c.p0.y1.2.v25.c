This is one way to rewrite the function by using a different approach other than bitwise operations which the original implementation used:


int sodium_hex2bin(unsigned char * bin, const size_t bin_maxlen, const char * hex, const size_t hex_len, const char * ignore, size_t * bin_len, const char ** hex_end) {
    size_t i, j;
    int ret = 0;
    char ch;
    
    for (i = 0, j = 0; i < hex_len; i++, hex++) {
        ch = tolower(*hex);
        
        /* Check for ignored characters */
        if (ignore != NULL && strchr(ignore, ch) != NULL) {
            continue;
        }
        
        /* Check if it's a hexadecimal digit */
        if (i % 2 == 0) {
            if (ch >= '0' && ch <= '9')
            {
                bin[j] = (ch - '0') << 4;
            }    
            else if (ch >= 'a' && ch <= 'f')
            {
                bin[j] = (ch - 'a' + 10) << 4;
            }
            else
            {
                errno = EINVAL;
                ret = -1;
                break;
            }  
        } else {
            if (ch >= '0' && ch <= '9')
            {    
                bin[j++] |= ch - '0';
            }    
            else if (ch >= 'a' && ch <= 'f')
            {
                bin[j++] |= ch - 'a' + 10;
            }
            else
            {
                errno = EINVAL;
                ret = -1;
                break;
            }
            if (j > bin_maxlen) {
              ret   = -1;
              errno = ERANGE;
              break;
            }
        }
    }

    /* Update the end pointers and binary length */
    if (hex_end != NULL) {
        *hex_end = hex;
    }
    if (bin_len != NULL) {
        *bin_len = j;
    }
    if (i < hex_len  ||  (hex_len % 2) != 0) {
        errno = EINVAL;
        ret = -1;
    }
    return ret;
}


This version works by converting the hex string on the go, identifying each character therefore it proceeds in simple manner as convert each pair of hex characters into binary, or return an error in case any of hex characters are not recognized or valid.