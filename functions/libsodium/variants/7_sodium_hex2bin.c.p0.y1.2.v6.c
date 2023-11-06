int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
                   const char *hex, const size_t hex_len,
                   const char *ignore, size_t *bin_len,
                   const char **hex_end)
{
    size_t binIndex = 0U, hexIndex = 0U, temp;
    int finalState = 0;
    unsigned char ch, ch_acc = 0U;

    while (hexIndex < hex_len) {
        ch = (unsigned char) hex[hexIndex];
        temp = ch ^ 48U;
        unsigned char ch_num0 = (temp - 10U) >> 8;
        temp= (ch & ~32U) - 55U;
        unsigned char ch_alpha0 = ((temp - 10U) ^ (temp - 16U)) >> 8;

        if ((ch_num0 | ch_alpha0) == 0U) {
            if (ignore != NULL && finalState == 0U && strchr(ignore, ch) != NULL) {
                hexIndex++;
                continue;
            }
            break;
        }

        temp = (ch_num0 & (ch ^ 48U)) | (ch_alpha0 & ((ch & ~32U) - 55U));
        if (binIndex >= bin_maxlen) {
            finalState = -1;
            errno = ERANGE;
            break;
        }
        if (finalState == 0U) {
            ch_acc = temp << 4U;
        } else {
            bin[binIndex++] = ch_acc | temp;
        }
        finalState = ~finalState;
        hexIndex++;
    }

    if (finalState != 0U) {
        hexIndex--;
        errno = EINVAL;
        finalState = -1;
    }
    if (finalState != 0) {
        binIndex = 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hexIndex];
    } else if (hexIndex != hex_len) {
        errno = EINVAL;
        finalState = -1;
    }
    if (bin_len != NULL) {
        *bin_len = binIndex;
    }
    
    return finalState;
}