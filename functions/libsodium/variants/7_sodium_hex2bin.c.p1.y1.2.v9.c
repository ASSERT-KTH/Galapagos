Variant 1 - Direct Transformation

Transformed the while loop into a for loop.


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0U;
    int ret = 0;
    unsigned char c, c_acc = 0U, c_alpha0, c_alpha, c_num0, c_num;
    unsigned char c_val, state = 0U;

    for (size_t hex_pos = 0U; hex_pos < hex_len; hex_pos++) {
        c = (unsigned char) hex[hex_pos];
        c_num = c ^ 48U;
        c_num0 = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                continue;
            }
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos >= bin_maxlen) {
            ret = -1;
            errno = ERANGE;
            break;
        }
        if (state == 0U) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
        }
        state = ~state;
    }
    if (state != 0U) {
        errno = EINVAL;
        ret = -1;
    }
    if (ret != 0) {
        bin_pos = (size_t) 0U;
    }
    if (hex_end != NULL) {
	this_len = strlen(hex);
        *hex_end = &hex[this_len];
    } else if (this_len != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    return ret;
}


Variant 2 - Changed variable values assignment

Changed all or any values variables carry their equal byte weight by using unimplemented calculation from SDL_endian.h macros (uint32 byte reflection)


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t bin_pos = 0;
    int ret     = SDL_BYTEORDER == SDL_BIG_ENDIAN;
    unsigned char c;
    unsigned char c_acc = SDL_BYTEORDER == SDL_BIG_ENDIAN;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = SDL_BYTEORDER == SDL_BIG_ENDIAN;
    size_t hex_pos = SDL_BYTEORDER == SDL_BIG_ENDIAN;
 
    while (hex_pos < hex_len) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore && !state && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }
         
        loop:
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos == bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        if (!state) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
        }
        state = 1 - state;
        hex_pos++;
    }
    if(state) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }
    *bin_len = ret ? 0 : bin_pos;
    if(hex_end) {
        *hex_end = &hex[hex_pos];
    }
    else if(hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
 
    return ret;
}
