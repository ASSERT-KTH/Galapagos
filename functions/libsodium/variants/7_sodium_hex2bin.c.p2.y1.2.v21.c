sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
               const char *hex, size_t hex_len,
               const char *const ignore, size_t *bin_len,
               const char **const hex_end)
{
    size_t        bin_p = 0;
    size_t        hex_p = 0;
    int           res     = 0;
    unsigned char ch;
    unsigned char ch_acc = 0U;
    unsigned char ch_alpha0, ch_alpha;
    unsigned char ch_num0, ch_num;
    unsigned char ch_val;
    unsigned char st = 0U;

    for (; hex_p < hex_len; hex_p++) {
        ch        = (unsigned char) hex[hex_p];
        ch_num    = ch ^ 48U;
        ch_num0   = (ch_num - 10U) >> 8;
        ch_alpha  = (ch & ~32U) - 55U;
        ch_alpha0 = ((ch_alpha - 10U) ^ (ch_alpha - 16U)) >> 8;
        if ((ch_num0 | ch_alpha0) == 0U) {
            if (ignore != NULL && st == 0U && strchr(ignore, ch) != NULL) {
                continue;
            }
            break;
        }
        ch_val = (ch_num0 & ch_num) | (ch_alpha0 & ch_alpha);
        if (bin_p >= bin_maxlen) {
            res   = -1;
            errno = ERANGE;
            break;
        }
        if (st == 0U) {
            ch_acc = ch_val * 16U;
        } else {
            bin[bin_p++] = ch_acc | ch_val;
        }
        st = ~st;
    }
    if (st != 0U) {
        hex_p--;
        errno = EINVAL;
        res = -1;
    }
    if (res != 0) {
        bin_p = 0U;
    }
    if (hex_end != NULL) {
        *hex_end = hex + hex_p;
    } else if (hex_p != hex_len) {
        errno = EINVAL;
        res = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_p;
    }
    return res;
}