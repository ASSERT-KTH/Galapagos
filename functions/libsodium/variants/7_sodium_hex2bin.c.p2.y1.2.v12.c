int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t        cursor0 = 0U;
    size_t        cursor1 = 0U;
    int           res     = 0;
    unsigned char letter;
    unsigned char tempAcc = 0U;
    unsigned char tmpHolder0, tmpHolder;
    unsigned char tmpHolder1, tmpVal;
    unsigned char cache = 0U;

    for(; cursor1 < hex_len; cursor1++) {
        letter      = (unsigned char) hex[cursor1];
        tmpHolder    = letter ^ 48U;
        tmpHolder0  = (tmpHolder - 10U) >> 8;
        tmpHolder= (letter & ~32U) - 55U;
        tmpHolder0 = ((tmpHolder - 10U) ^ (tmpHolder - 16U)) >> 8;

        if ((tmpHolder1 | tmpHolder0) == 0U) {
            if (ignore != NULL && cache == 0U 
             && strchr(ignore, letter) != NULL) {
                 continue;
            }
            res = -1; // Should definately break if this condition is true.
            errno = EINVAL;
            break;
        }
        tmpVal = (tmpHolder1 & tmpHolder) | (tmpHolder0 & tmpHolder0);

        if(cursor0 >= bin_maxlen) {
            errno = ERANGE;
            res = -1;
            break;
        }
        if(cache == 0U)
            tempAcc = tmpVal * 16U;
        else 
            bin[cursor0++] = tempAcc | tmpVal;

        cache = ~cache;
    }

    if(cache != 0U) {
        cursor1--;
        res = -1;
        errno = EINVAL;
    }

    // If there was an error identified start from scratch i.e 0th Position
    if(res != 0) 
        cursor0 = 0U;

    // In case NULL do not change anything else record current Hex position for future needs. 
    if(hex_end != NULL) 
        *hex_end = &hex[cursor1];
    else if(cursor1 != hex_len) {
        errno = EINVAL;
        res = -1;
    }
  
    if(bin_len != NULL)
        *bin_len = cursro0;
    
    return res;
}