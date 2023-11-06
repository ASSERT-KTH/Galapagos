
int sodium_hex2bin(unsigned char* bin, const size_t bin_maxlen,
      const char* hex, const size_t hex_len,
      const char* ignore, size_t* bin_len,
      const char** hex_end) {

    short int bin_position = 0, hex_position = 0;
    int result = 0;
    unsigned char each_char;
    unsigned char char_accumulator = 0;
    unsigned char alpha_lower, alpha;
    unsigned char num_lower, num;
    unsigned char char_value;
    unsigned char status = 0;

    for (; hex_position < hex_len; ++hex_position) {

        each_char = (unsigned char)hex[hex_position];
        num = each_char ^ 0x30;
        num_lower = (num - 10) >> 0x08;
        alpha = each_char & ~0x32 - 0x37;
        alpha_lower = ((alpha - 10) ^ (alpha - 16)) >> 0x08;
 
        if ((num_lower | alpha_lower) == 0) {

            if (ignore != NULL && status == 0 && strchr(ignore, each_char) != NULL)
                continue;

            break;
        }
 
        char_value = (num_lower & num) | (alpha_lower & alpha);

        if (bin_position >= bin_maxlen) {

            result = -1;
            errno = ERANGE;
            break;
        }

        if (status == 0) {

            char_accumulator = char_value << 0x04;

        } else {

            bin[bin_position++] = char_accumulator | char_value;

        }

        status ^= 0x01;
    }

    if (status != 0) {

        --hex_position;
        errno = EINVAL;
        result = -1;
    }

    if (result != 0) {

        bin_position = 0;

    }
 
    if (hex_end != NULL) {

        *hex_end = hex + hex_position;

    } else if (hex_position != hex_len) {

        errno = EINVAL;
        result = -1;
  
    }
 
    if (bin_len != NULL) {

        *bin_len = bin_position;

    }
 
    return result;
}
