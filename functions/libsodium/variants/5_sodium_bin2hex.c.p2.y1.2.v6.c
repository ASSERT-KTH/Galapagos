void sodium_bin2hex(char *hex, const size_t hex_maxlen,
                    const unsigned char *bin, const size_t bin_len) 
{
    size_t i = 0;
    int  c;
    int  b;
    unsigned int y;

    if (bin_len >= SIZE_MAX/2 || hex_maxlen <= bin_len * 2) {
        return NULL; // if the condition doesn't hold, returning NULL 
    }
    for (i = 0; i < bin_len; i++) {
        b = (bin[i] >> 4);
        c = bin[i] & 15;
        y = ((unsigned char) (87 + c + (((c - 10) >> 8) & ~38))) |
                ((unsigned char) (87 + b + (((b - 10) >> 8) & ~38))) << 8;
        hex[2*i]= (char) (y >> 8);
        hex[2*i + 1] = (char) y;
    }
    hex[bin_len * 2] = 0;
    return hex;
}