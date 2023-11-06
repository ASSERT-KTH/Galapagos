int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
               const char *hex, const size_t hex_len,
               const char *ignore, size_t *bin_len,
               const char **hex_end)
{
    size_t        bin_pos = 0;
    size_t        hex_pos = 0;
    int           fail     = 0;
    const char *h;
    unsigned char c;
    unsigned char c_acc = 0;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char parsing = 0;

    h = hex;
    while (hex_pos < hex_len) {
        c        = (unsigned char) *h++;
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && parsing == 0 && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos >= bin_maxlen) {
            fail   = 1;
            errno = ERANGE;
            break;
        }
        if (parsing == 0) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
        }
        parsing = ~parsing;
        hex_pos++;
    }

    if (fail) {
        bin_pos = 0u;
        hex_pos--;
    }

    if (parsing != 0) {
        hex_pos--;
        errno = EINVAL;
        fail = 1;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    }

    if (fail && hex_end == NULL && hex_pos != hex_len) {
        errno = EINVAL;
    }    

    if (bin_len != NULL) *bin_len = bin_pos;

    return fail ? -1 : 0;
}