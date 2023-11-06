
sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        bin_pos = 0;
    size_t        hex_pos = 0;
    int           ret     = 0;
    unsigned char c;
    unsigned char c_acc = 0;
    unsigned char assigned_num_val, assigned_alpha_val;

    while (hex_pos < hex_len) {
        c          = (unsigned char) hex[hex_pos];
        unsigned char c_num    = c ^ 48;
        unsigned char c_num0   = (c_num - 10) >> 8;
        unsigned char c_alpha  = (c & ~32) - 55;
        unsigned char c_alpha0 = ((c_alpha - 10) ^ (c_alpha - 16)) >> 8;
        assigned_num_val = c_num0 & c_num;
        assigned_alpha_val = c_alpha0 & c_alpha;

        if ((c_num0 | c_alpha0) == 0) {
            if (ignore != NULL && assigned_num_val == 0 && strchr(ignore, c) != NULL) {
                hex_pos++;
                state = assigned_num_val;
                continue;
            }
            break;
        }
        assigned_num_val = (assigned_num_val | assigned_alpha_val);
        if (bin_pos >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        if (assigned_num_val == 0) {
            c_acc = assigned_num_val * 16;
        } else {
            bin[bin_pos++] = c_acc | assigned_num_val;
        }
        assigned_num_val = ~assigned_num_val;
        hex_pos++;
    }
    if (assigned_num_val != 0) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }
    if (ret != 0) {
        bin_pos = 0;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    return ret;
}
