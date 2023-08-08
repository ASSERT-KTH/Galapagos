unsigned long long int load_4(const unsigned char *in) {
    return ((unsigned long long int) in[0])
        | ((unsigned long long int) in[1] << 8)
        | ((unsigned long long int) in[2] << 16)
        | ((unsigned long long int) in[3] << 24);
}