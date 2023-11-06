Variant 1 - Using different variable names 

sodium_hex2bin(unsigned char *buffer, const size_t buffer_max_size,
               const char *input, const size_t input_size,
               const char *ignored, size_t *output_size,
               const char **end_point)
{
    size_t        buffer_position = 0U;
    size_t        input_position = 0U;
    int           result     = 0;
    unsigned char char_under_examination;
    unsigned char char_accumulator = 0U;
    unsigned char char_alpha0, char_alpha;
    unsigned char char_number0, char_number;
    unsigned char char_value;
    unsigned char conversion_state = 0U;

    while (input_position < input_size) {
        char_under_examination        = (unsigned char) input[input_position];
        char_number                   = char_under_examination ^ 48U;
        char_number0                  = (char_number - 10U) >> 8;
        char_alpha                    = (char_under_examination & ~32U) - 55U;
        char_alpha0 = ((char_alpha - 10U) ^ (char_alpha - 16U)) >> 8;
        if ((char_number0 | char_alpha0) == 0U) {
            if (ignored != NULL && conversion_state == 0U && strchr(ignored, char_under_examination) != NULL) {
                input_position++;
                continue;
            }
            break;
        }
        char_value = (char_number0 & char_number) | (char_alpha0 & char_alpha);
        if (buffer_position >= buffer_max_size) {
            result   = -1;
            errno = ERANGE;
            break;
        }
        if (conversion_state == 0U) {
            char_accumulator = char_value * 16U;
        } else {
            buffer[buffer_position++] = char_accumulator | char_value;
        }
        conversion_state = ~conversion_state;
        input_position++;
    }
    if (conversion_state != 0U) {
        input_position--;
        errno = EINVAL;
        result = -1;
    }
    if (result != 0) {
        buffer_position = 0U;
    }
    if (end_point != NULL) {
        *end_point = &input[input_position];
    } else if (input_position != input_size) {
        errno = EINVAL;
        result = -1;
    }
    if (output_size != NULL) {
        *output_size = buffer_position;
    }
    return result;
}


Variant 2 - With reordered if-else checks (for variances in assembly opcodes)


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    // .. All Variable Declarations ..

    if (bin_len != NULL) {
        *bin_len = bin_pos;
    } else {
        errno = EINVAL;
        ret = -1;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    }

    if (ret != 0) {
        bin_pos = 0U;
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }

    // ... calculations and other if else checks without no changes...
    return ret;
}