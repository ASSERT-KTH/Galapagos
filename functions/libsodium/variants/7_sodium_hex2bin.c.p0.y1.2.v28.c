
int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen,
                   const char *hex, const size_t hex_len,
                   const char *ignore, size_t *bin_len,
                   const char **hex_end)
{
    const char *const hex_end_pdu = hex + hex_len;
    size_t    bin_idx = 0U;
    uint8_t   accumulator = 0U;
    int       is_adding_high_nibble = 1;

    uint8_t   tmp;

    while (hex < hex_end_pdu) {
        tmp = (uint8_t) (*hex);
        is_adding_high_nibble ^= 1;

        if (((tmp = (tmp | 32U)) >= 'a') && (tmp <= 'f')) {
            tmp -= ('a' - 10);
        }
        else if ((tmp >= '0') && (tmp <= '9')) {
            tmp -= '0';
        }
        else if (ignore && strchr(ignore, tmp)) {
            ++hex;
            continue;
        }
        else {
            break;
        }
        
        if(is_adding_high_nibble) {
          accumulator = tmp << 4;
        }
        else if(bin_idx < bin_maxlen) {
          bin[bin_idx++] = accumulator | tmp;
        }
        else {
            errno = ERANGE;
            return -1;
        }

        ++hex;
    }

    if (!is_adding_high_nibble) {
        --hex;
        errno = EINVAL; //Incomplete byte
        return -1; 
    }

    if (bin_len) {
        *bin_len = bin_idx;
    }

    if (hex_end) {
        *hex_end = hex;
    }
    else if (hex != hex_end_pdu) {
        errno = EINVAL; //Does not convert whole string 
        return -1; 
    }

    return 0;
}
