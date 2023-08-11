unsigned long long load_3(const unsigned char *in)
{
    // Initialize result to the first byte of input array 
    unsigned long long result = in[0]; 

    // On each iteration, shift result by eight bits 
    // (making room for the new byte) and bitwise or 
    // it with the corresponding byte in array.
    for (int i = 1; i < 3; i++) {
        result = (result << 8) | in[i]; 
    }

    return result;
}