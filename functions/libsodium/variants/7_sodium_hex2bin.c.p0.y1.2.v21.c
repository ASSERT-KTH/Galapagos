Here is an example of an alternate implementation that converts a hexadecimal string to its binary representation.


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) {
    size_t        bin_pos = 0;
    size_t        hex_pos = 0;
    int           ret     = 0;

    unsigned char hex_digit;

    while (hex_pos < hex_len) {
        char c = hex[hex_pos];
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'F') ||
            (c >= 'a' && c <= 'f')) {
            
            // convert hex digit to binary value
            if (c>='0' && c<='9') {
                hex_digit = c - '0';
            } else if (c>='A' && c<='F') {
                hex_digit = c - 'A' + 10;
            } else { // c must be a lowercase a-f
                hex_digit = c - 'a' + 10;
            }

            // If character should be ignored
            if (ignore != NULL && strchr(ignore, c)) {
                hex_pos++;
                continue;
            }

            // overflow
            if (bin_pos >= bin_maxlen) {  
                ret = -1;
                errno = ERANGE;
                break;
            }

            // Write binary values in pairs
            if (hex_pos % 2 == 0) {
                bin[bin_pos/2] = hex_digit << 4;
            } else {
                bin[bin_pos/2] |= hex_digit;   
            }
            
            bin_pos++;
        } else { 
            errno = EINVAL;
            ret = -1;
            break;
        }
        hex_pos++;
    }

    if(ret==0 && bin_pos!=hex_len) {
        errno = EINVAL;
        ret = -1;
    }

    if (ret != 0) {
        bin_pos = 0;
    }
    if (hex_end != NULL) {
        *hex_end =&hex[hex_len];
    }

    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    
    return ret;
}


This alternate implementation lists each case explicitly rather than utilizing bitwise operations, which can make the code more direct and easier to understand.