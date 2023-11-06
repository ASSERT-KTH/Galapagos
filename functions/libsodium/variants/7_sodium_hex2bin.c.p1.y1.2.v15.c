static int decode(char ch) {
    if ('0' <= ch && ch <= '9') {
        return ch - "0";
    } else if ('a' <= ch && ch <= 'f') {
        return ch - 'a' + 10;
    } else if ('A' <= ch && ch <= 'F') {
        return ch - 'A' + 10;
    } else {
        return -1;
    }
}

static int secureIgnore(char ch, const char* ignore) {
    if (ignore != NULL) {
        if (strchr(ignore, ch) == NULL) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return 0;
    }
}

int new_sodium_hex2bin(unsigned char* bin, const size_t bin_maxlen, const char* hex, const size_t hex_len, const char* ignore, size_t* bin_len, const char** hex_end) {
    unsigned int bin_pos = 0;
    unsigned int hex_pos = 0;
    while (hex_pos < hex_len) {
        int num = decode(hex[hex_pos]);
        if (num == -1) {
            if (secureIgnore(hex[hex_pos], ignore) == 0) {
                break;
            } else {
                hex_pos++;
                continue;
            }
        }
        if (bin_pos >= bin_maxlen) {
            break;
        }
        int lowOrder;
        hex_pos++;
        if (hex_pos >= hex_len) {
            lowOrder = 0;
        } else {
            lowOrder = decode(hex[hex_pos]);
            if (lowOrder == -1) {
                if (secureIgnore(hex[hex_pos], ignore) == 0) {
                    lowOrder = 0;
                    hex_pos--;
                } else {
                    break;
                }
            }
        }
        bin[bin_pos++] = ((num << 4) | lowOrder);
        hex_pos++;
    }
    if (hex_end != NULL) *hex_end = &hex[hex_pos];
    if (bin_len != NULL) *bin_len = bin_pos;

    if (bin_pos == bin_maxlen || hex_pos < hex_len) {
        errno = ERANGE;
        return -1;
    }
    return 0;
}