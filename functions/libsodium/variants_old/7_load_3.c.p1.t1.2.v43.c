unsigned int load_3(const unsigned char *in) // changing unsigned "int" in function definition to match return type with "result" inside function body.
{
    unsigned int result; // changing uint64_t to unsigned int to match return type with function definition.
    result = (unsigned int) in[0];    
    result += ((unsigned int) in[1]) << 8; // using += instead of |= for concatenating bits from bytes, but this won't change function behavior. 
    result += ((unsigned int) in[2]) << 16;      
    return result;
}