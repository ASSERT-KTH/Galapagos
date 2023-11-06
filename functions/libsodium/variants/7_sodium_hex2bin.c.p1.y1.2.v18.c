Below, you'll find the variant of the `sodium_hex2bin()` function preserving its original functionality.

The adopted transformations in this case are:
- Local variables initialization throughout of the function, instead of the start.
- Improvement in control flow
- Slight modification in function logic.


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)                                           
{                                               
    int ret = 0;                                       
    size_t hex_pos = 0U, bin_pos = 0U;  

    unsigned char state = 0U;

    while (hex_pos < hex_len) {

        unsigned char c = hex[hex_pos];
        
        unsigned char c_num = c ^ 48U;
        unsigned char c_num0 = (c_num - 10U) >> 8;

        unsigned char c_alpha = (c & ~32U) - 55U;
        unsigned char c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        
        if (!(c_num0 | c_alpha0)) {
            if (!(ignore != NULL && state == 0U && strchr(ignore, c) != NULL)) {

                ret = (bin_pos >= bin_maxlen) ? -1 : ret;
                if (ret == -1) {
                    errno = ERANGE;
                    break;
                }

                unsigned char c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
                unsigned char c_acc = (state == 0U) ? c_val * 16U : 0U;

                bin[bin_pos++] = (state == 0U) ? c_acc : c_acc | c_val;

                state = ~state;
            }
            hex_pos++;
        } else {
            break;
        }
    }
    
    state != 0U ? errno = EINVAL, ret = -1 : hex_pos--;
  
    if(ret == 0) {
        if(hex_end != NULL) {
            *hex_end = &hex[hex_pos];
        } else {
            (hex_pos != hex_len) ? errno = EINVAL, ret = -1 : ret;
        }

        if (bin_len != NULL) {
            *bin_len = bin_pos;
        }
    } else {
        bin_pos = 0U;
    }
      
    return ret;
}
