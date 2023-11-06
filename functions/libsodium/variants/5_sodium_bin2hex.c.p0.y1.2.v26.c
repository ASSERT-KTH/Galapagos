Here is the equivalent substituted code:


char *sodium_bin2hex(char *const hex_str, const size_t hex_len, const unsigned char *const bin, const size_t bin_len) {
    size_t i;
    unsigned char upper, lower;

    if (bin_len * 2U >= hex_len || bin_len >= SIZE_MAX / 2) {
        sodium_misuse();
    }
    for (i = 0; i < bin_len; i++) {
        upper = bin[i] >> 4;
        lower = bin[i] & 0xf;
        hex_str[2 * i] = upper + (upper < 10 ? 48 : 87);
        hex_str[2 * i + 1] = lower + (lower < 10 ? 48 : 87);
    }
    hex_str[2 * i] = '\0';

    return hex_str;
}

This substitute version of the function does more or less the same thing as the original function but the condition to check `if bin_len * 2U >= hex_len | bin_len >= SIZE_MAX / 2 ` is slightly different.

Then in the loop, it still separates each byte into upper (`upper = bin[i] >> 4`) and lower (`lower = bin[i] & 0xf`) portions that correspond to hex values. Then uses a ternary operator to decide whether to add 48 or 87 based on the hex value is less than 10 or not. 

It then stores those values back into the hex string (`hex_str[2 * i] `& `hex_str[2 * i + 1] `respectively) on spots that are calculated somewhat differently than the original function.

Then terminates the hex string (`hex_str[2 * i] = '\0'`) and returns the final string. So, the processing is slightly differently done, but the final function does the same thing as the original question. It converts binary string to corresponding hexadecimal string.