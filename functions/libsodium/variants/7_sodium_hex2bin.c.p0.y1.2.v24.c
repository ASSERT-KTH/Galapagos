int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen, const char *hex, size_t hex_len, const char *ignore, size_t *bin_len, const char **hex_end)
{
    size_t bpos = 0, hpos = 0;
    unsigned char ch, val, acc = 0, alpha, alpha0, num, num0, tmp;
    int error = 0;
    while (hpos < hex_len)
    {
        ch = (unsigned char)hex[hpos];
        num = ch ^ 48U;
        num0 = (num - 10U) >> 8;
        alpha = (ch & ~32U) - 55U;
        alpha0 = ((alpha - 10U) ^ (alpha - 16U)) >> 8;
        if (!(num0 | alpha0)) {
            if (ignore && !tmp && strchr(ignore, ch))
                hpos++;
            else
                break;
            continue;
        }
        val = (num0 & num) | (alpha0 & alpha);
        if (bin && bpos >= bin_maxlen) {
            errno = ERANGE;
            error = -1;
            break;
        }
        if (tmp) bin[bpos++] = acc | val;
        else acc = val << 4;
        tmp = ~tmp;
        hpos++;
    }
    if (tmp) {
        hpos--;
        errno = EINVAL;
        error = -1;
    }
    if (error) {
        bpos = 0;
    }
    if (bin_len) {
        *bin_len = bpos;
    }
    if (hex_end) {
        *hex_end = &hex[hpos];
    } else if (hpos != hex_len) {
        errno = EINVAL;
        error = -1;
    }

    return error;
}