sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) 
{
    size_t        bin_pos = 0U;
    size_t        hex_pos = 0U;
    int           error_check = 0;
    unsigned char curr_character;
    unsigned char accumulated_char = 0U;
    unsigned char alpha_mag, alpha_boolean_value;
    unsigned char num_mag, num_boolean_value;
    unsigned char character_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        curr_character = (unsigned char) hex[hex_pos];
        num_mag = curr_character ^ 48U; 
        num_boolean_value = (num_mag - 10U) >> 8;
        alpha_mag = (curr_character & ~32U) - 55U;
        alpha_boolean_value = ((alpha_mag - 10U) ^ (alpha_mag - 16U)) >> 8;
        if (num_boolean_value | alpha_boolean_value == 0U) {
            if (ignore && !state && strchr(ignore,curr_character)) {
                ++hex_pos;
                continue;
            }
            break;
        }
        character_val = (num_boolean_value & num_mag) | (alpha_boolean_value & alpha_mag);
        if (bin_pos >= bin_maxlen) {
        
            error_check = -1;
            errno = ERANGE;
            break;
        }
        
        // alternate between intermediate delimiter and final char assembly
        bin_pos += state;
        assembled_char = state ? 
                                    (character_val | accumulated_char) :
                                    (character_val * 16);
        state ^= 1;
        ++hex_pos;
    }
    
    // check if hex string ended half-byte early
    if (state) {
        errno = EINVAL;
        error_check = -1;
    }

    bin_pos *= (1 - error_check);

    // if required, point to where function ended parsing hex
    if (hex_end) {
        *hex_end = hex + hex_pos;
    } else if(hex_pos != hex_len) {
    // check if string ended abruptly
        errno = EINVAL;
        error_check = -1;
    }
  
    // set num characters created
    if (bin_len) {
        *bin_len = bin_pos;
    }
    return error_check;
}