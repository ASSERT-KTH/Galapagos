int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen,
                   const char *hex, size_t hex_len,
                   const char *ignore, size_t *bin_len,
                   const char **hex_end)
{
    size_t bin_i = 0, hex_i = 0;
    int conversion = 0;
    unsigned char accumulator = 0U;
    unsigned char c, corner_case0, corner_case, alpha0, alpha;
    
    while (hex_i < hex_len) {
        c = (unsigned char) hex[hex_i];
        corner_case = c ^ 48U;
        corner_case0 = (corner_case - 10U) >> 8;
        alpha = (c & ~32U) - 55U;
        alpha0 = ((alpha - 10U) ^ (alpha - 16U)) >> 8;
        if ((corner_case0 | alpha0) == 0U) {
            if (ignore != NULL && conversion == 0U && strchr(ignore, c) != NULL) {
                hex_i++;
                continue;
            }
            break;
        }
        c = (corner_case0 & corner_case) | (alpha0 & alpha);
        if (bin_i >= bin_maxlen) {
            conversion   = -1;
            errno = ERANGE;
            break;
        }
        if (conversion == 0U) {
            accumulator = c * 16U;
        } else {
            bin[bin_i++] = accumulator | c;
        }
        conversion = ~conversion;
        hex_i++;
    }
    if (conversion != 0U) {
        hex_i--;
        errno = EINVAL;
        conversion = -1;
    }
    if (conversion != 0) {
        bin_i = (size_t) 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_i];
    } else if (hex_i != hex_len) {
        errno = EINVAL;
        conversion = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_i;
    }
    return conversion;
}