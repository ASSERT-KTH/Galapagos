char *sodium_bin2hex(char *hex, const size_t hex_maxlen,
                      const unsigned char *bin, const size_t bin_len) {
    const char hex_map[] = "0123456789abcdef";
    size_t click = 0;

    if (hex == NULL || bin == NULL || 
        bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    for (click = 0; click < bin_len; ++click) {
        hex[2*click]     = hex_map[(bin[click] & 0xF0) >> 4];
        hex[2*click + 1] = hex_map[bin[click] & 0x0F];
    }
    hex[2*click] = '\0';

    return hex;
}