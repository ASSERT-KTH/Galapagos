
int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
               const char *hex, const size_t hex_len,
               const char *ignore, size_t *bin_len,
               const char **hex_end)
{
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    int ret = 0;
    unsigned char buffer;
    unsigned char bin_val = 0U;
    unsigned char c_alpha, alpha;
    unsigned char c_num, num;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        buffer     = (unsigned char) hex[hex_pos];
        num        = buffer ^ 48U;
        c_num      = (num - 10U) >> 8;
        alpha      = (buffer & ~32U) - 55U;
        c_alpha = ((alpha - 10U) ^ (alpha - 16U)) >> 8;
        if ((c_num | c_alpha) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, buffer) != NULL) {
                hex_pos++;
                continue;
            }
            ret = -1;
            break;
        }
        c_val = (c_num & num) | (c_alpha & alpha);
        if (bin_pos >= bin_maxlen) {
            errno = ERANGE;
            ret = -1;
            break;
        }
        else{
            if (state == 0U) {
                bin_val = c_val * 16U;
            } 
            else {
                bin[bin_pos++] = bin_val | c_val;
            }
            state = ~state;
        }
        hex_pos++;
    }
    if (ret != 0) {
        bin_pos = 0U;
    }
           
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } 
    else if (hex_pos+1 != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
        
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
   
    return ret;
}
