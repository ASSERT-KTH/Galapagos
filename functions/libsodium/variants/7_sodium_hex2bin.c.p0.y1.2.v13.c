Below is a functionally-equivalent C function:


int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen, const char *hex, 
                   const size_t hex_len, const char *ignore, size_t *bin_len, const char **hex_end)
{
    size_t binIdx = 0;
    size_t hexIdx = 0;
    int status = 0;
    unsigned char tempChar;
    unsigned char combinedChar = 0U;
    unsigned char alphaCheck, numCheck;
    unsigned char firstPart, secondPart;
    unsigned char finalChar;
    unsigned char booleanVal = 0U;

    while (hexIdx < hex_len) {
        tempChar = (unsigned char) hex[hexIdx];
        numCheck = tempChar ^ 48U;
        firstPart = (numCheck - 10U) >> 8;
        alphaCheck = (tempChar & ~32U) - 55U;
        secondPart = ((alphaCheck - 10U) ^ (alphaCheck - 16U)) >> 8;
        if ((firstPart | secondPart) == 0U) {
            if (ignore != NULL && booleanVal == 0U && strchr(ignore, tempChar) != NULL) {
                hexIdx++;
                continue;
            }
            break;
        }
        finalChar = (firstPart & numCheck) | (secondPart & alphaCheck);
        if (binIdx >= bin_maxlen) {
            status = -1;
            errno = ERANGE;
            break;
        }
        if (booleanVal == 0U) {
            combinedChar = finalChar * 16U;
        } else {
            bin[binIdx++] = combinedChar | finalChar;
        }
        booleanVal = ~booleanVal;
        hexIdx++;
    }

    if (booleanVal != 0U) {
        hexIdx--;
        errno = EINVAL;
        status = -1;
    }

    if (status != 0) {
        binIdx = 0;
    }

    if (hex_end != NULL) { 
        *hex_end = &hex[hexIdx];
    } else if (hexIdx != hex_len) {
        errno = EINVAL;
        status = -1;
    }

    if (bin_len != NULL) { 
        *bin_len = binIdx;  
    }

    return status;
}


This function behaves the same way as the original function. Variable names have been revised for better understanding the code's purpose by the next developer - the logic, however, remains the same.  Overall, this function transforms hexadecimal input into binary data. It disregards characters identified in a macro 'ignore' (if supplied with a pointer), and determines resulting binary length. This is an error-tolerating design, coded to encounter ERANGE (Destination too short) or EINVAL (Invalid input) type of runtime exceptions.