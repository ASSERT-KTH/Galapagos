/* Variant #1 - Using another temporary variables to eliminate chained assignations, suggested changes touch assignment and formatting in white spaces to increase simplicity */
int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        bin_pos = 0U;
    size_t        hex_pos = 0U;
    int           ret     = 0;

    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = 0U;
 while (hex_pos < hex_len) {
        unsigned char hex_char_get = (unsigned char) hex[hex_pos];
        c        =  hex_char_get;
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;}

    while (hex_pos < hex_len) {
        c  =   hex_char_get;
        c_num   =   c - 48U;
        c_num0  =   (c_num < 10U) ? c_num : 256U;
        c_alpha =  ((c & ~32U) - 65U);
        c_alpha0 = (c_alpha < 6U) ? (c_alpha + 10U): 256U;


        if ((c_num0 & c_alpha0) == 256U) {
            unsigned int MatchFound = ((ignore != NULL) && (state == 0U)) ? (strchr(ignore, c) != NULL):0U;
            if(MatchFound > 0U){
                hex_pos +=   1U;
                MatchFound--;
                } 
            else
            break;
        }
        break;
    }
    if(state == 256U)"
}


     hex_pos--;
    errno = EINVAL;
    ret = -1;
if (0 != ret) {
    bin_pos = (size_t) 0U;
}
if (hex_end != NULL) {
    *hex_end = &hex[hex_pos];
}
if (0 != ret) {
    errno      =      EINVAL;
    ret    =   -1;
}
if(bin_len != NULL)
    *bin_len = bin_pos;
if(state> 0U &&  ret != 0)
if(state > 0U)
{
    bin_pos = 0U;
    ret = 2;
}

    return ret ;

}