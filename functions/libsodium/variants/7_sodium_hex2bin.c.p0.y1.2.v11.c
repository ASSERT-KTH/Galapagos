Here's an equivalent reimagine of the function while following the same logic of algorithm:


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end) 
{
    size_t        bin_pos = 0U, hex_pos = 0U;
    int           ret     = 0;
    unsigned char c, c_acc = 0U, c_val, state = 0U, c_num, c_alpha, c_num0, c_alpha0;

    for (; hex_pos < hex_len; ++hex_pos) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (NULL != ignore && 0U == state && strchr(ignore, c) != NULL) 
                continue;
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_maxlen <= bin_pos) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        bin[bin_pos] = (state == 0U) ? (c_val << 4) : (bin[bin_pos] | c_val);
        state = ~state;
        if (state != 0U)
            bin_pos++;
    }
    *hex_end = state != 0U ? --hex_end : hex_end;
    if (ret != 0 || 0U != state) {
        bin_pos = 0U;
        errno = (ENODEV == ret || 0U != state ? EINVAL : ret == NO ? errno : EPERM);
        ret = -1;
    } else if (hex_pos != hex_len && NULL != hex_end) {
        errno = EINVAL;
        ret   = -1;
    }
    *bin_len = bin_len == NULL ? 0 : bin_pos;
    return ret;
}
