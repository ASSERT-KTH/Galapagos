Here is a program variant using bitwise operations:


uint64_t load_3(const unsigned char *in) 
{
    uint64_t result;

    result =  (uint64_t) in[2] << 16;
    result |= (uint64_t) in[1] << 8;
    result |= (uint64_t) in[0];

    return result;
}


The behavior still remains the same; i.e., reading the same input `in` will produce the same (expected) result where order of the bitwise operation changes without affecting functionality.