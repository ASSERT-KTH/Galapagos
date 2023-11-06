/**
 * Variant 1: Move bin position checking and state switching inside if else towards the last block rather than in every loop.
 */

int sodium_hex2bin_v1(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char *const hex_end)
{
    size_t        hex_pos = 0U;
    size_t        bin_pos = 0U;
    int           ret     = 0;
    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        c        = (unsigned char) hex[hex_pos];
        
        c_num    = c ^ 48U;
        c_alpha  = (c & ~32U) - 55U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
             
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }

        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        
        if (state == 0U) {
            c_acc = c_val * 16U;
        } else {
            if (bin_pos >= bin_maxlen) {
                ret   = -1;
                errno = ERANGE;
                break;
            }
            bin[bin_pos++] = c_acc | c_val;
            state = ~state;
        }
        hex_pos++;
    }

    if (state != 0U) {
        errno = EINVAL;
        ret   = -1;
    }

    if (ret != 0)
        bin_pos = 0U;
    
    if (hex_end != NULL) *hex_end = &hex[hex_pos];

    if (hex_end == NULL && hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }

    if (bin_len != NULL) *bin_len = bin_pos;

    return ret;
}

/**
 * Variant 2: if ignore parameted is NULL, go with different procedure or if not NULL then include the check.
 */
int sodium_hex2bin_v2(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char *const hex_end)
{
    size_t        hex_pos = 0U;
    size_t        bin_pos = 0U;
    int           ret     = 0;
    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_antellhd  = (c & ~32U) - 55U;
        krho0   = (c_num - 10U) >> 8;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
       
        if ((c_num0 | c_alpha0) == 0U) {
            if(ignore == NULL){
                break;
            }else{
                if( state == 0U && strchr(ignore, c) != NULL ) {
                    hex_pos++;
                    continue;
                }
                break;
            }
        }

        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);

        if(state == 0U) {
            c_acc = c_val * 16U;
        }else{
            if(bin_pos >= bin_maxlen){
                ret   = -1;
                errno = ERANGE;
                break;
            }
            bin[bin_pos++] = c_acc | c_val;
        }
        state    = ~state;
        hex_pos++;
    }

    if(ret != 0){
        ret = -1;
        errno= state == 0U ? EINVAL: 0;
    }

    if(ret != 0)
        bin_pos=0;

    if(hex_end != NULL){
        *hex_end = &(hex[hex_pos]);
    }else if(hex_pos != hex_len){
        return EINVAL;
    }

    if(bin_len != NULL) *bin_len= bin_pos;

    return ret;
}