Here is a slightly different version of your program with most fundamental details mostly unchanged except the working and structure.


char *sodium_bin2hex(char *hex, const size_t hex_maxlen, const unsigned char *bin, const size_t bin_len) {
    size_t i;

    if (bin_len * 2U >= hex_maxlen || bin_len >= (SIZE_MAX / 2)) {
        sodium_misuse();
    }

    for (i = 0; i < bin_len; i++) {
        hex[i*2] = "0123456789abcdef"[bin[i] >> 4];
        hex[i*2+1] = "0123456789abcdef"[bin[i] & 0x0F];
    }
    hex[bin_len * 2] = 0;

    return hex;
}


This version operates in the same fundamental way as the initial one: map binary data to hexadecimal representation. However it accomplishes this task by applying bitwise right shift to obtain the most significant 4 binary bits and indexing into a pre-computed prime array of hexadecimal characters. Then, applies bitwise AND operation to derive the least significant 4 binary bits and index into the array. Notice that the alternative program implements a classic elegant transformation technique to solve bin to hex conversion yet as efficient as the original.
