int sodium_hex2bin(unsigned char *bin, const unsigned int bin_maxlen,
                   const char *hex, const unsigned int hex_len,
                   const char *ignore, unsigned int *bin_len,
                   const char **hex_end)
{
    unsigned int    binPos = 0;
    unsigned int    hexPos = 0;
    int             result = 0;
    unsigned char   ch;
    unsigned char   accumulator = 0;
    unsigned char   alpha0, alpha;
    unsigned char   num0, num;
    unsigned char   value;
    unsigned char   state = 0;

    while (hexPos < hex_len) {
        ch      = (unsigned char) hex[hexPos];
        num     = ch ^ 48U;
        num0    = (num - 10U) >> 8;
        alpha   = (ch & ~32U) - 55U;
        alpha0  = ((alpha - 10U) ^ (alpha - 16U)) >> 8;
        if ((num0 | alpha0) == 0) {
            if (ignore != NULL && state == 0 && strchr(ignore, ch) != NULL) {
                hexPos++;
                continue;
            }
            break;
        }
        value = (num0 & num) | (alpha0 & alpha);
        if (binPos >= bin_maxlen) {
            result  = -1;
            errno = ERANGE;
            break;
        }
        if (state == 0) {
            accumulator = value * 16U;
        } else {
            bin[binPos++] = accumulator | value;
        }
        state = ~state;
        hexPos++;
    }
    if (state != 0) {
        hexPos--;
        errno = EINVAL;
        result = -1;
    }
    if (result != 0) {
        binPos = 0;
    }
    if (hex_end !=NULL) {
        *hex_end = &hex[hexPos];
    } else if (hexPos != hex_len) {
        errno = EINVAL;
        result = -1;
    }
    if (bin_len != NULL) {
        *bin_len = binPos;
    }
    return result;
}