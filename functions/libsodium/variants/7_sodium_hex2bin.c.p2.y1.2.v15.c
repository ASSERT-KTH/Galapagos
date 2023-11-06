sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        bin_pos = (size_t) 0U;
    size_t        hex_pos = (size_t) 0U;
    int           ret     = 0;
    unsigned char buffer;

    while (hex_pos < hex_len) {
        unsigned char c       = (unsigned char) hex[hex_pos];
        unsigned char c_num   = c ^ 48U;
        unsigned char c_num0  = (c_num - 10U) >> 8;
        unsigned char c_alpha = (c & ~32U) - 55U;
        unsigned char c_alpha0= ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if ((c_num0 | c_alpha0) != 0U) {
            buffer = (c_num0 & c_num) | (c_alpha0 & c_alpha);
            if (ret == 0) {
                if (ignore && strchr(ignore, c) != NULL) {
                   hex_pos++;
                    continue;
                }
                ret += buffer * 16U;
            } else {
                if (bin_pos >= bin_maxlen) {
                    errno = ERANGE;
                    break;
                }
                bin[bin_pos++] = ret | buffer;
                ret = 0;
            }
        } else {
            // IGNORING the unknown character
            errno = EINVAL;
            break;
        }
        hex_pos++;
    }
    if (ret != 0) {
        hex_pos--;
        bin_pos = (size_t) 0U;
        errno = EINVAL;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    if (hex_pos != hex_len) {
        errno = EINVAL;
    }
    return (hex_pos == hex_len)? ret : -1;
}