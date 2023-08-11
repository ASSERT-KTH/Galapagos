Here is a an alternate version of the provided code that maintains its functionality:


uint64_t load_3(const unsigned char *in) {
    uint64_t result = 0;

    for (int i = 0; i < 3; i++)
    {
        result |= ((uint64_t) in[i]) << (i * 8);
    }

    return result;
}

The main difference here is that this version makes use of a loop to perform the shifting and OR operations, promoting elegancy and reduction of redundancy. Despite these changes, it achieves the same results as the initial function.