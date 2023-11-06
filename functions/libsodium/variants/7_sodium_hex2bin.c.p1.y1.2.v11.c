
int revised_sodium_hex2bin(unsigned char *bin, size_t bin_maxlen, 
                           const char *hex, size_t hex_len,
                           const char *ignore, size_t *bin_len,
                           const char **hex_end)
{
    size_t bin_position = 0;
    size_t hex_position = 0;
    int result   = 0;
    unsigned char hex_char;
    unsigned char char_accumulator = 0;
    unsigned char alpha_first, alpha;
    unsigned char num_first, num;
    unsigned char val;
    unsigned char progress = 0;

    while (hex_position < hex_len) {
        hex_char = (unsigned char) hex[hex_position];
        num = hex_char ^ 48;
        num_first = (num - 10) >> 8;
        alpha  = (hex_char & ~32) - 55;
        alpha_first = ((alpha - 10) ^ (alpha - 16)) >> 8;
        if ((num_first | alpha_first) == 0) {
            if (ignore != NULL && progress == 0 && strchr(ignore, hex_char) != NULL) {
                hex_position++;
                continue;
            }
            break;
        }
        val = (num_first & num) | (alpha_first & alpha);
        if (bin_position >= bin_maxlen) {
            result = -1;
            errno = ERANGE;
            break;
        }
        if (progress == 0) {
            char_accumulator = val * 16;
        } else {
            bin[bin_position++] = char_accumulator | val;
        }
        progress = ~progress;
        hex_position++;
    }
    if (progress != 0) {
        hex_position--;
        errno = EINVAL;
        result = -1;
    }
    if (result != 0) {
        bin_position = 0;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_position];
    } else if (hex_position != hex_len) {
        errno = EINVAL;
        result = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_position;
    }
    return result;
}
