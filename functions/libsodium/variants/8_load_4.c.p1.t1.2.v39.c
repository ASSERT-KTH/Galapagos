Here is a variant of the program that maintains the function's original functionality but changes the behavior slightly by using a for loop:


uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;

    for (int i = 0; i < 4; i++) {
        result |= ((uint64_t) in[i]) << (8 * i);
    }

    return result;
}


This variant does the same thing as the original function, but it does so with a loop and results in more condensed and arguably simplified code. As in the original implementation, it converts an array of 4 bytes into a 64-bit integer. The value of each byte is shifted appropriately according to its position in the array (with the help of the loop counter i), then added to the result.