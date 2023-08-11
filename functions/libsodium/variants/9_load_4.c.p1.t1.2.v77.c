unsigned long load_4(const unsigned char *in) {
    unsigned long result;
    for(int i = 0; i < 4; i++) {
        result |= ((unsigned long) in[i]) << (i * 8);
    }
    return result;
}