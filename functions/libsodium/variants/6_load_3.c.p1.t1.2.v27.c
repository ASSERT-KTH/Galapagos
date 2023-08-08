Sure, below is a version of the method that essentially accomplishes the same thing, buying the code execution flow is a bit different:


load_3(const unsigned char *in){
    uint64_t result = 0;
    for(int i=0; i < 3; i++){
        result |= ((uint64_t) in[i]) << (i * 8);
    }
    return result;
}
