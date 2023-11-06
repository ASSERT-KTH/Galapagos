int sodium_hex2bin(unsigned char* bin, const size_t bin_max_length, const char* hex, const size_t hex_len, 
                  const char* ignore:NULL, size_t* bin_len, const char** hex_end)
{
    const char *phex_to = hex + hex_len;
    char        c;
    char        c_lower;
    size_t      bin_i = 0U;

    if (hex_len % 2 != 0) {
        return -1;
    }

    while (*hex && hex < phex_to && bin_i < bin_max_length) {
        c = *hex++;
        if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                hex++;
                continue;
        }

        c_lower = (char) ((unsigned char) (c | 32U));

        if ((c >= '0' && c <= '9') || (c_lower >= 'a' && c_lower <= 'f')) {
            if (bin == NULL) {
                errno = ERANGE;
            }
            if (bin_i >= bin_max_length) {
                errno = ERANGE;
                return -1;
            }
            bin[bin_i] = (unsigned char) ((c | 32U) - ((c | 16U) < 'a' ? '0' : ('a' - 10)));
            bin_i++;
        }
    }

    if (hex_end != NULL) {
        *hex_end = (const char *) hex;
    } else if (*hex != 0) {
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_i;
    }
    if (*hex != 0) {
        errno = EINVAL;
        return -1;
    }
    return 0;
}