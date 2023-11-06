Here is a similar implementation of the function in C.


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end) 
{

    int           ret = 0;
    size_t        hex_pos, bin_pos = 0;
    unsigned char high_digit, low_digit;

    for (hex_pos = 0; hex_pos < hex_len; hex_pos++) {        
        
        if (hex[hex_pos] > 57) 
            high_digit = hex[hex_pos] - 'a' + 10;
        else
            high_digit = hex[hex_pos] - '0';

        if (high_digit > 15) 
        {
            if (ignore != NULL && strchr(ignore, hex[hex_pos]) != NULL)
                continue;
            else {
                ret = -1;
                errno = EINVAL;
                break;
            }
        }
        hex_pos++;

        if (hex_pos >= hex_len) {
            bin[bin_pos++] = high_digit;
            if (hex_end != NULL)
                *hex_end = &hex[hex_pos--];
            break;
        }

        if (bin_pos >= bin_maxlen) {
            bin[bin_pos++] = high_digit;
            *hex_end = &hex[hex_pos--];
            ret   = -1;
            errno = ERANGE;
            break;
        }

        if (hex[hex_pos] > 57) 
            low_digit = hex[hex_pos] - 'a' + 10;
        else
            low_digit = hex[hex_pos] - '0';

        if (low_digit > 15) 
        {
            if (ignore != NULL && strchr(ignore, hex[hex_pos]) != NULL) {               
                bin[bin_pos++] = high_digit;
                hex_pos--;
                continue;                            
            } 
            else {
                ret = -1;
                errno = EINVAL;
                break;
            }
        }
        
        bin[bin_pos++] = (high_digit << 4) | low_digit;                
     }

    if(bin_len)
        *bin_len = bin_pos;
  
    return ret;
}

  
Please note that there are not strict algorithms or exact recipes to refactor a code, hence these version can be significantly different in layout, still being bitwise equivalent.