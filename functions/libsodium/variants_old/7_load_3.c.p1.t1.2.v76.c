Here is a program variant that changes the behavior of the original function while maintaining its original functionality. It has used the right shift operator and addition together rather than using bitwise OR along with left shift.


uint64_t load_3(const unsigned char *in)
{
    uint64_t result;
    result = ((uint64_t) in[2]) << 16;
    result += ((uint64_t) in[1]) << 8;
    result += (uint64_t) in[0];
    
    return result;
}

In this variant program, the byte at in[2] is set first, preserving the byte order of the original function. The right bits provision for the other two bytes is cleared by shifting them to left instead of using bitwise OR. This way, on adding the three, the same multi-byte loading will be achieved with alternate mechanism.