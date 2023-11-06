/*
Here is a equivalent substitute implementation of the sodium hex2_bin() implementation.
*/

int sodium_hex2bin(unsigned char *const bin_loc, const size_t bin_maxlen,
           const char *const hex_sub, const size_t hex_len,
           const char *const ignore_sub, size_t *const bin_len,
           const char **const hex_end)
{
    size_t bin_i = 0U;
    size_t hex_i = 0U;
    unsigned int hex_part;
    unsigned char loc_c;
    unsigned char tot_minus_state = -1;

    errno = 0;
    while (hex_i < hex_len) {
        int is_ignore_val = ignore_sub != NULL && strchr(ignore_sub, hex_sub[hex_i]) != NULL;
        loc_c = (unsigned char) hex_sub[hex_i];
        hex_part = loc_c - 48U;
        if (hex_part > 9) {
            hex_part = loc_c - 55U & ~0x20;
            if (hex_part - 10U > 5)
                break;
        }
        hex_i++;
        if (hex_i >= hex_len)
            is_ignore_val = 1;
        else if (is_ignore_val)
            continue;

        bin_i += ~tot_minus_state;
        bin_loc[bin_i] <<= 4U;
        bin_loc[bin_i] |= hex_part;
        if (bin_i < bin_maxlen)
            tot_minus_state = ~tot_minus_state;
        else
            errno = ERANGE;
    }
    *bin_len=bin_i;

    if (hex_end != NULL)
        *hex_end = &hex_sub[hex_i];
    if (tot_minus_state||errno)
        errno = EINVAL;
    return -errno;
}