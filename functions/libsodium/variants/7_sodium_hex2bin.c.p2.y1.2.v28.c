sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        bin_pos = 0U, hex_pos = 0U;
    int           ret     = 0;
    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char vals, checker;
    unsigned char state = 0U;
    

    for (; hex_pos < hex_len; hex_pos++) {
        c        = (unsigned char) hex[hex_pos];
        unsigned char decoded[2] = {c ^ 48U, (c & ~32U) - 55U};
        vals  = ((decoded[0] - 10U) >> 8) & decoded[0];
        vals |= (((decoded[1] - 10U) ^ (decoded[1] - 16U)) >> 8) & decoded[1];
        
        checker = ((decoded[0] - 10U) >> 8) | (((decoded[1] - 10U) ^ (decoded[1] - 16U)) >> 8);
        
        if (checker == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                continue;
            }
            break;
        }
    
        if (bin_pos >= bin_maxlen) {
            ret   = errno = ERANGE;
            break;
        }
        
        bin[bin_pos] = state ? c_acc | vals : (c_acc = vals * 16U);
        if (state) {
            bin_pos++;
        }        
        state = ~state;
    }

    if (state) {
        hex_pos--;
        ret = errno = EINVAL;
    }

    if (ret) {
        bin_pos = 0U;
    }

    if (hex_end) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        ret = errno = EINVAL;
    }

    if (bin_len)
        *bin_len = bin_pos;
    
    return ret;
}