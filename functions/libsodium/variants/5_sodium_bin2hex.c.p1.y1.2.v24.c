// Variation 1
char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    unsigned int x;

    // Sanity check
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    // Process the binary data
    for (size_t i = 0; i < bin_len; ++i) {
        unsigned char c = bin[i];
        x = (unsigned char)(87U+c+(((c-10U)>>8)&~38U)) << 8 | (unsigned char)(87U+(c>>4)+((((c>>4)-10U)>>8)&~38U));
        hex[i * 2] = (char)x;
        hex[i * 2U + 1] = (char)(x >> 8);
    }
    hex[bin_len * 2] = '\0';

    return hex;
}

// Variation 2
char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (size_t i = 0U; i < bin_len; ++i) {
        int c = bin[i] & 0xf;
        int b = bin[i] >> 4;
        unsigned int x = ((unsigned char)(87U+c+(((c-10U)>>8)&~38U)) << 8) |
                         (unsigned char)(87U+b+(((b-10U)>>8)&~38U));
        hex[i * 2U] = (char)x;
        hex[i * 2U + 1U] = (char)(x >> 8);
    }
    hex[bin_len * 2U] = '\0';
    
    return hex;
}

// Variation 3
char *sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    size_t i = 0U;
    int b, c;
    unsigned int x;
    
    if (bin_len < SIZE_MAX / 2 && hex_maxlen > bin_len * 2U) {
        do {
           c = bin[i] & 0xf; 
           b = bin[i++] >> 4;
           x = (unsigned int)((unsigned char)(87U+c+(((c-10U)>>8)&~38U)) << 8) |
               (unsigned char)(87U+b+(((b-10U)>>8)&~38U));
           hex[(i - 1) * 2U] = (char)x;
           hex[(i - 1) * 2U + 1] = (char)(x >> 8U);
        } while (i < bin_len);
    } else {
        sodium_misuse();
    }
    hex[bin_len * 2U] = '\0';
    
    return hex;
}