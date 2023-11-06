unsigned char * castAndShift(const unsigned char element, const short shift){
    return ((uint64_t) element) << shift; 
}

const unsigned char load_4(const unsigned char *in)
{
    return castAndShift(in[0],0) | 
           castAndShift(in[1],8) |
           castAndShift(in[2],16) |
           castAndShift(in[3],24);
}