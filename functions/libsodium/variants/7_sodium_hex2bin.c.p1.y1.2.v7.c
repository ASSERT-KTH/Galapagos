Below are few transformed code variants of the original function, this is done by rearranging the behaviours and conditions without changing original functionality:

Variant 1:


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0U, hex_pos = 0U;
    int    ret     = 0;
    unsigned char c, c_acc = 0U, state = 0U;

    while (hex_pos < hex_len) {
        
        unsigned char c_val, c_num0, c_alpha0;
        c = (unsigned char) hex[hex_pos];

        if (bin_pos >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        
        c_num0 = (((c ^ 48U) - 10U) >> 8);
        c_alpha0 = ((((c & ~32U) - 55U) - 10U) ^ ((c & ~32U) - 55U) - 16U) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }

        c_val = (c_num0 & (c ^ 48U)) | (c_alpha0 & ((c & ~32U) - 55U));
        
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

    if (bin_len != NULL) {
        *bin_len = (ret != 0) ? 0U : bin_pos;
    }
  
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
 
    return ret;
}
  

Variant 2: 


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0U, hex_pos = 0U;
    int ret = 0;
    unsigned char c, c_acc = 0U, state = 0U;
    
    while (true) {
        
        if(hex_pos >= hex_len) break;

        unsigned char c_val, c_num0, c_alpha0;
        c        = (unsigned char) hex[hex_pos];
        c_num0   = ((c ^ 48U) - 10U) >> 8;
        c_alpha0 = ((((c & ~32U) - 55U) - 10U) ^ (((c & ~32U) - 55U) - 16U)) >> 8;
        
        if ((c_num0 | c_alpha0) == 0U) {
            if(ignore != NULL && state==0U && strchr(ignore, c)!=NULL){
                hex_pos++;
                continue;
            } else 
                break;
        }
        
        if (bin_pos >= bin_maxlen) {
            errno = ERANGE;
            return -1;
        }

        c_val                 = (c_num0 & (c ^ 48U)) | (c_alpha0 & ((c & ~32U) - 55U));
        bin[bin_pos - state] += (state == 0U) ? (c_val << 4U) : c_val;
        
        bin_pos += state;
        state = ~state;
        hex_pos++;
    }

    if(state != 0U) {
        hex_pos--;
        errno = EINVAL;
        return -1;
    }

    *bin_len  = (bin_len != NULL) ? 0 : bin_pos;
    
    if(hex_end != NULL)
        *hex_end = &hex[hex_pos];
    else if(hex_pos != hex_len) {
        errno = EINVAL;
        return -1;
    }
    
    return 0;
}
