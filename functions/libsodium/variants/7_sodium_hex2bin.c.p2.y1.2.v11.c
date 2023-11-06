int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
               const char *hex, const size_t hex_len,
               const char *ignore, size_t *bin_len,
               const char **hex_end)
{
    size_t        binMarker = (size_t) 0U;
    size_t        hexMarker = (size_t) 0U;
    int           output    = 0;
    unsigned char hexVal;
    unsigned char CumulativeHexValue = 0U;
    unsigned char isAlpha0, isAlpha;
    unsigned char isNumeric0, isNumeric;
    unsigned char CalculatedValue;
    unsigned char switcher = 0U;

    while (hexMarker < hex_len) {
        hexVal    = (unsigned char) hex[hexMarker];
        isNumeric    = hexVal ^ 48U;
        isNumeric0   = (isNumeric - 10U) >> 8;
        isAlpha   = (hexVal & ~32U) - 55U;
        isAlpha0 = ((isAlpha - 10U) ^ (isAlpha - 16U)) >> 8;
        if ((isNumeric0 | isAlpha0) == 0U) {
            if (ignore != NULL && switcher == 0U && strchr(ignore, hexVal) != NULL) {
                hexMarker++;
                continue;
            }
            break;
        }
        CalculatedValue = (isNumeric0 & isNumeric) | (isAlpha0 & isAlpha);
        if (binMarker >= bin_maxlen) {
            output   = -1;
            errno = ERANGE;
            break;
        }
        if (switcher == 0U) {
            CumulativeHexValue = CalculatedValue * 16U;
        } else {
            bin[binMarker++] = CumulativeHexValue | CalculatedValue;
        }
        switcher = ~switcher;
        hexMarker++;
    }
    if (switcher != 0U) {
        hexMarker--;
        errno = EINVAL;
        output = -1;
    }
    if (output != 0) {
        binMarker = (size_t) 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hexMarker];
    } else if (hexMarker != hex_len) {
        errno = EINVAL;
        output = -1;
    }
    if (bin_len != NULL) {
        *bin_len = binMarker;
    }
    return output;
}