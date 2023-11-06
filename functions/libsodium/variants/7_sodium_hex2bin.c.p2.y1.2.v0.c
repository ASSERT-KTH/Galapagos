sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0U, hex_pos = 0U;
    int ret = 0;
    unsigned char c, c_acc = 0U, c_alpha, c_alpha0, c_num, c_num0, c_val;
    unsigned char state = 0U;

    for (; hex_pos < hex_len; hex_pos++) {
        c = (unsigned char) hex[hex_pos];
        c_num = c ^ 48U;
        c_num0 = (c_num - 10U) >> 8;
        c_alpha = (unsigned char) (c & ~32U) - 55U;
        c_alpha0 = (unsigned char)((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore && !state && strchr(ignore, c))  {
                continue;
            }
            break;
        }

        c_val = (unsigned char) ((c_num0 & c_num) | (c_alpha0 & c_alpha));
        if (bin_pos >= bin_maxlen) {
            errno = ERANGE;
            ret = -1;
            break;
        }
        bin_pos += !(state = ~state) ? c_acc = c_val * 16U, 0 : (bin[bin_pos] = c_acc | c_val, 1);
    }

    if (state)
    {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }

    ret && (bin_pos = 0U);

    if (hex_end)
        *hex_end = &hex[hex_pos];
    else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }

    if (bin_len)
        *bin_len = bin_pos;

    return ret;
}