Using pointer syntax for Array operations variant
-------------------------------------------------

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
const char *const hex, const size_t hex_len,
const char *const ignore, size_t *const bin_len,
const char **const hex_end)
{
    unsigned char *bin_pos_byte = bin;
    const char     *hex_pos_char   = hex;
    int           ret     = 0;
    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos_char - hex < hex_len) {
        c        = (unsigned char) *hex_pos_char++;
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                continue;
            }
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos_byte - bin >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        if (state == 0U) {
            c_acc = c_val * 16U;
        } else {
           *bin_pos_byte++ |= c_acc | c_val;
        }
        state = ~state;
    }
    if (state != 0U) {
        hex_pos_char--;
        errno = EINVAL;
        ret = -1;
    }
    if (ret != 0) {
        bin_pos_byte = bin;
    }
    if (hex_end != NULL) {
        *hex_end = hex_pos_char;
    } else if (hex_pos_char != hex + hex_len) {
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) {
      *bin_len = bin_pos_byte - bin;
   }
     return ret;
}


By eliminating auxiliary variables
-----------------------------------

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
const char *const hex, const size_t hex_len,
const char *const ignore, size_t *const bin_len,
const char **const hex_end)
{
    size_t        bin_pos = (size_t) 0U;
    size_t        hex_pos = (size_t) 0U;
    int           ret     = 0;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        ret        = strchr(ignore, (unsigned char) hex[hex_pos]) != NULL && ignore != NULL && state==0U;
        int condition = (((cv=(((unsigned char) hex[hex_pos]) ^ 48U) - 10U) >> 8) | ((cv=(cv & ((unsigned char) hex[hex_pos]) - 55U - 10U ^ cv - 16U) >>8) == 0U) ;
      
        if (condition  && (!ret)) {
            break;
        }
        cv = c_val = ((cv & (((unsigned char) hex[hex_pos]) ^ 48U)) | cv & ((unsigned char) hex[hex_pos]) - 55U);
        if (bin_pos >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        if (state == 0U) {
            (((unsigned char) hex[hex_pos]) ^ 48U) = c_val * 16U;
        } else {
            bin[bin_pos++] = (((unsigned char) hex[hex_pos]) ^ 48U) | c_val;
        }
        state = ~state;
        hex_pos++;
    }
    if (state != 0U) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }
    if (ret == 0) {
       hex_pos != hex_len ? (errno = EINVAL,ret=-1): (&hex[hex_pos],&bin[hex_pos]);
       bin_len != NULL ? *bin_len = hex_pos:0;
    }
    return ret;
}
