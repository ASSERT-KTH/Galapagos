/* Function Variant 1: 
   Using 'ternary operator' instead 'if' constructs for 'errno' setting and 'hex_pos++' incrementation
*/


int sodium_hex2bin_v1(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t    bin_pos = 0U;
    size_t    hex_pos = 0U;
    int       ret     = 0;
    unsigned char c, c_acc = 0U;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        c      = (unsigned char) hex[hex_pos];
        c_num  = c ^ 48U;
        c_num0 = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) ? ++hex_pos : 0;
            continue;
        }
        c_val  = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        ret = bin_pos >= bin_maxlen ? (ret = -1, errno = ERANGE, -1) : 0;
        if (state == 0U) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
        }
        state = ~state;
        hex_pos++;
    }
    if (state != 0U) {
        hex_pos--;
        errno = (ret=-1, EINVAL);
    }
    Bin_pos = ret != 0 ? 0U : bin_pos;
    *hex_end = hex_end != NULL ? &hex[hex_pos] : NULL;
    if (hex_end == NULL && hex_pos != hex_len) {
        errno = (ret=-1, EINVAL);
    }
    *bin_len = bin_len != NULL ? bin_pos : 0U;
    return ret;
}

/*
Function Variant 2:
Moved decrementation of 'state' inside 'if' constructs and ternary operator for '*hex_end'.
Follows style given where each line does one operation.
Primary change was assigning true and false values to 'state'
*/


int sodium_hex2bin_v2(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{

/* no @ and ZERO transformation */
