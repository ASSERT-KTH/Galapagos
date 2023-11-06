Despite the original function being focused on performance and low-level detail, a simpler, less optimized alternative of turning a hexadecimal string into binary would imitate the actions performed but make use of more standard library functions, losing out on some of the performance benefits of the optimized bitwise operations.

Here's a possible alternative:


#include <stdlib.h>
#include <string.h>

int sodium_hex2bin(unsigned char *bin, size_t max_bin_len, 
                   const char *hex, size_t hex_len, 
                   const char *ignore, size_t *bin_len,
                   const char **hex_end) 
{
    size_t bin_pos = 0, hex_pos = 0;
    int ignoreFound, conversion;
    
    for (; hex_pos < hex_len; hex_pos += 2) {
        // Ignore specified characters
        if (ignore) {
            if (strchr(ignore, hex[hex_pos])) {
                hex_pos++;
                continue;
            }
        }
        if (hex_pos + 1 < hex_len) {
            conversion = sscanf(&hex[hex_pos], "%2hhx", &bin[bin_pos]);
            if(conversion != 1) {
                // Invalid Hex input case handled; Similar to EINVAL
                errno = EINVAL; // An invalid argument was given
                return -1;
            }
            bin_pos++;
        }
        // Revised binary.length condition check now also check if there was a half complete byte conversion
        if (bin_pos >= max_bin_len || hex_pos + 2 > hex_len) {
            // Binary array overfilling scenario and half complete byte conversation handled; Similar to ERANGE
            errno = ERANGE; // Result too large
            return -1;
        }
    }
    
    if (bin_len != NULL) {           // Save parsed binary length if bin_len is not NULL
        *bin_len = bin_pos;
    }
    if (hex_end != NULL) {           // Save the reamining unprocessed hex string if hex_end is not NULL
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) { // Invalidate the situation when the hex processing isn't complete when hex_end was NULL
        errno = EINVAL;              // An invalid argument was given
        return -1;
    }
    
    return 0;
}


Understanding this topic thoroughly, intiating changes are made, based on understanding rather than blind implementation. High-level changes like recognizing the portion manipulating characters makes it worth effort than calculation and using a scan operation instead where relevant.
Ultimately, these ideas can potentially improve the understandability of the hex-to-bin procedure.

This less performance-oriented structure can keep similar error scenarios alive via equivalents provided using the C Standard Library than custom-made portions using necessarily complex bitwise activities, performing fundamentally the same operation.