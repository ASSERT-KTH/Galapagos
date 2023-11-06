unsigned char sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
                             const char *hex, const size_t hex_len,
                             const char *ignore, size_t *bin_len,
                             const char **hex_end) 
{
    unsigned char c, c_acc = 0U, c_val;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char output = 0U;

    size_t hex_pos = 0U;
    size_t bin_pos = 0U;    

    for (; hex_pos < hex_len; hex_pos++) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if (ignore != NULL && output == 0U && strchr(ignore, c)) {
            continue;      
        } 
        else if ((c_num0 | c_alpha0) == 0U || bin_pos >= bin_maxlen) {
            errno = (bin_pos >= bin_maxlen) ? ERANGE : EINVAL;
            bin_pos = 0U;
            output = ~output;
            break;
        }

        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        bin[bin_pos] = (output == 0U) ? c_val * 16U : (bin[bin_pos] | c_val);
        output = ~output;
        bin_pos += (output == 0U ? 1 : 0);   
    }
     
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    } 

    if(hex_end != NULL) {
        *hex_end = &(hex[hex_pos]);
    }
    else if (hex_pos != hex_len) {
        errno = EINVAL;
    }
   
    return (output != 0U) ? (-1) : bin_pos;
}