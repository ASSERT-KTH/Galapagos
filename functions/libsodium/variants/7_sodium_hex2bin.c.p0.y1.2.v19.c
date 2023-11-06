
int sodium_hex2bin(unsigned char * bin, const size_t bin_maxlen,
             const char * const hex, const size_t hex_len,
             const char * const ignore, size_t * * const bin_len,
             const char * * const hex_end) {

    size_t binPosition = 0;
    size_t hexPosition = 0;
    int sodiumStatus = 0;

    // Temporary Variables for Hexadecimal Conversion
    unsigned char hexCharacter;
    unsigned char accumulatedDigit = 0U;
    unsigned char alpha_digit_numeric0, parsingDigit;
    unsigned char numeric_digit, numeric_digit_0;
    unsigned char extractedDigit;
    unsigned char parsingPhase = 0U;

    // Hexadecimal Parsing Loop
    while (hexPosition < hex_len) {
        hexCharacter = (unsigned char) hex[hexPosition];
        numeric_digit = hexCharacter ^ 48U;
        numeric_digit_0 = (numeric_digit - 10U) >> 8;
        parsingDigit = (hexCharacter & ~32U) - 55U;
        alpha_digit_numeric0 = ((parsingDigit - 10U) ^ (parsingDigit - 16U)) >> 8;

        if ((numeric_digit_0 | alpha_digit_numeric0) == 0U) {
 
            if (ignore && parsingPhase == 0U && strchr(ignore, hexCharacter) != NULL) {
                hexPosition++;
                continue;
            }
            break;
        }

        extractedDigit = (numeric_digit_0 & numeric_digit) | (alpha_digit_numeric0 & parsingDigit);
        if (binPosition >= bin_maxlen) {
            sodiumStatus = -1;
            errno = ERANGE;
            break;
        }
        if (parsingPhase == 0U) {
            accumulatedDigit = extractedDigit << 4U; 
        } else {
            bin[binPosition++] = accumulatedDigit | extractedDigit;
        }

        parsingPhase ^= 1U;
        hexPosition++;
    }

    if (parsingPhase) {
        hexPosition--;
        errno = EINVAL;
        sodiumStatus = -1;
    }

    if (sodiumStatus) {
        binPosition = 0;
    }

    if (hex_end) {
        *hex_end = &hex[hexPosition];
    } else if (hexPosition < hex_len) {
        errno = EINVAL;
        sodiumStatus = -1;
    }

    if (bin_len) {
        *bin_len = binPosition;
    }

    return sodiumStatus;
}
