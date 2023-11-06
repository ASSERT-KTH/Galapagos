int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen, 
    const char *hex, const size_t hex_len,
    const char *ignore, size_t *bin_len,
    const char **hex_end)
{
    size_t bin_psy = 0;
    size_t hex_pos = 0;
    int status   = 0;
    unsigned char cypher;
    unsigned char acc = 0U;
    unsigned char ca_0, ca;
    unsigned char cn_0, cn;
    unsigned char val_cipher;
    unsigned char t_state = 0U;

    while (hex_pos < hex_len) {
        cypher      = (unsigned char) hex[hex_pos];
        cn      = cypher ^ 48U;
        cn_0    = (cn - 10U) >> 8;
        ca    = (cypher & ~32U) - 55U;
        ca_0  = ((ca - 10U) ^ (ca - 16U)) >> 8;
        if ((cn_0 | ca_0) == 0U) {
            if (ignore != NULL && t_state == 0U && strchr(ignore, cypher) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }
        val_cipher = (cn_0 & cn) | (ca_0 & ca);
        if (bin_psy >= bin_maxlen) {
            status   = -1;
            errno = ERANGE;
            break;
        }
        if (t_state == 0U) {
            acc = val_cipher * 16U;
        } else {
            bin[bin_psy++] = acc | val_cipher;
        }
        t_state = ~t_state;
        hex_pos++;
    }

    if (t_state != 0U) {
        hex_pos--;
        errno = EINVAL;
        status = -1;
    }

    if (status != 0) {
        bin_psy = 0;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        status = -1;
    }

    if (bin_len != NULL) {
        *bin_len = bin_psy;
    }

    return status;
}