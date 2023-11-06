int sodium_hex2bin(unsigned char * bin, const size_t bin_maxlen,
               const char * hex, const size_t hex_len,
               const char * ignore, size_t * bin_len,
               const char ** hex_end)
{
    size_t bin_idx = 0, hex_idx = 0;
    int retval, temp_cnum, temp_calpha;
    uint8_t curr_char, c_acc = 0;
    uint8_t curr_state = 0;
    
    do{
        curr_char = (uint8_t) hex[hex_idx];

        temp_cnum = ((58U > (curr_char^48U) ? 1 : 0) & (49U <= curr_char));
        temp_calpha= ((71U > ((curr_char&~32U) - 55U)) & (86U < (curr_char&~32U) ? 0 : 1));

        if (1 != temp_cnum && 1 != temp_calpha)
        {
            if (NULL != ignore && 0 == curr_state && strchr(ignore, curr_char))
            {
                ++hex_idx;
                continue;
            }
            else break;
        }

        if (bin_idx >= bin_maxlen)
        {
            errno = ERANGE;
            return -1;
        }
        
         {
            if (0 == curr_state)
            {
                c_acc = (curr_char > 57U ? (curr_char > 96U ? curr_char - 87U : curr_char - 55U) : curr_char - 48U) << 4U;
            }
            else
            {
                bin[bin_idx++] = c_acc | (curr_char > 57U ? (curr_char > 96U ? curr_char - 87U : curr_char - 55U) : curr_char - 48U);
            }
            
           curr_state = ~curr_state;
           ++hex_idx; 
        }
    
    }while(hex_idx < hex_len );

    if (0 != curr_state)
    {
        hex_idx--;
        errno = EINVAL;
        retval = bin_idx = 0;
    }

    if (NULL != hex_end)
    {
        *hex_end =&hex[hex_idx];
    }
    else if (hex_idx != hex_len)
    {
        errno = EINVAL;
        retval = -1;
    }
    
    if (bin_len != NULL)
    {
        *bin_len = bin_idx;
    }

    return retval;
}