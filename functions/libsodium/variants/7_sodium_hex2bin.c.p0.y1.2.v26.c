int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
               const char *hex, const size_t hex_len,
               const char *ignore, size_t *bin_len,
               const char **hex_end)
{
    size_t b_pos = 0;
    size_t h_pos = 0;
    int result = 0;
    unsigned char ch;
    unsigned char b_accumulator = 0;
    unsigned char ch_alp0, ch_alp;
    unsigned char ch_num0, ch_num;
    unsigned char ch_val;
    unsigned char state = 0;

    while (h_pos < hex_len) {
        ch = (unsigned char) hex[h_pos];
        ch_num = ch ^ 48;
        ch_num0 = (ch_num - 10U) >> 8;
        ch_alp = (ch & ~32U) - 55U;
        ch_alp0 = ((ch_alp - 10U) ^ (ch_alp - 16U)) >> 8;
        if ((ch_num0 | ch_alp0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, ch) != NULL) {
                h_pos++;
                continue;
            }
            break;
        }
        ch_val = (ch_num0 & ch_num) | (ch_alp0 & ch_alp);
        if (b_pos >= bin_maxlen) {
            result   = -1;
            errno = ERANGE;
            break;
        }
        if (state == 0U) {
            b_accumulator = ch_val << 4;
        } else {
            bin[b_pos++] = b_accumulator | ch_val;
        }
        state = ~state;
        h_pos++;
    }

    if (state != 0U) {
        --h_pos;
        errno = EINVAL;
        result = -1;
    }
    if (result != 0) {
        b_pos = 0;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[h_pos];
    } else if (h_pos != hex_len) {
	    errno = EINVAL;
        result =-1;
    }
    if (bin_len != NULL) {
	    *bin_len = b_pos;
    }
    return result;
}