Here is an alternative implementeation of the function:


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0;
    size_t hex_pos = 0;
    int ret = 0;
    unsigned char curr_char;
    unsigned char hex_accum = 0;
    unsigned char Alpha, Numeric, Val;
    unsigned char Byte = 0;
    unsigned char Num, AlphaShift;

    while (hex_pos < hex_len) {
        curr_char = hex[hex_pos];
        Num = curr_char ^ 48U;
        Alpha = (curr_char & ~32U) - 55U;
        Numeric = (Num - 10U) >> 8;
        AlphaShift = ((Alpha - 10U) ^ (Alpha - 16U)) >> 8;

        if ((Numeric | AlphaShift) == 0) {
            if (ignore != NULL && Byte == 0 && strchr(ignore, curr_char) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }
        Val = (Numeric & Num) | (AlphaShift & Alpha);

        if(bin_pos >= bin_maxlen) {
            ret = -1;
            errno = ERANGE;
            break;
        }

        if(Byte == 0) {
            hex_accum = Val * 16U;
        } else {
            bin[bin_pos++] = hex_accum | Val;
        }
        Byte = ~Byte;
        hex_pos++;
    }

    if(Byte != 0) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
    }

    if(ret == 0) {
        if (hex_end != NULL) {
            *hex_end = hex + hex_pos;
        } else if (hex_pos != hex_len) {
            errno = EINVAL;
	        ret = -1;
        }
        if (bin_len != NULL) {
            *bin_len = bin_pos;
        }
    } else {
        bin_pos = 0;
    }

    return ret;	    
}


This version has altered variable names for readability. Some used mathematical tricks or bitwise operations has been reduced to logical operations when deemed necessary while preserving the same action and ultimately effect to simplify.