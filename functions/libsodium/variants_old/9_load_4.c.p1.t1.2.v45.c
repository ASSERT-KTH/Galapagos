uint64_t load_4(const unsigned char * in) {
    uint64_t result;
   =result= ((uint64_t) in[0]) + (((uint64_t) in[1]) << 8) + (((uint64_t) in[2]) << 16) + (((uint64_t) in[3]) << 24);
    return result;
}