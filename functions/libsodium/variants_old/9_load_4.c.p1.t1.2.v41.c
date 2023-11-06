Here's a C program variant that changes the behavior of the original function:


unsigned long long load_4_alt(const unsigned char *from) {
    unsigned long long value;

    memcpy(&value, from, sizeof(unsigned long long));

    return value;
}
