int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t        i = 0, j = 0;
    int           result = 0;
    unsigned char temp, combination, number_quad, alphabet_quad;

    while (i < hex_len) {
        temp = (unsigned char) hex[i];
        number_quad = temp ^ 48U;
        number_quad = (number_quad - 10U) >> 8;
        alphabet_quad = (temp & ~32U) - 55U;
        alphabet_quad = ((alphabet_quad - 10U) ^ (alphabet_quad - 16U)) >> 8;

        if ((number_quad | alphabet_quad) == 0U) {
            if (ignore != NULL && strchr(ignore, temp) != NULL) {
                i++;
                continue;
            }
            break;
        }

        combination = (number_quad & temp) | (alphabet_quad & temp);

        if (j >= bin_maxlen) {
            result   = -1;
            errno = ERANGE;
            break;
        }

        if ((j & 1) == 0) {
            bin[j / 2] = combination << 4;
        } else {
            bin[j / 2] |= combination;
        }

        j++;
        i++;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[i];
    }

    if (j & 1) {
        errno = EINVAL;
        i--;
        result = -1;
    }

    if (bin_len != NULL) {
        *bin_len = j / 2;
    }

    return result;
}
