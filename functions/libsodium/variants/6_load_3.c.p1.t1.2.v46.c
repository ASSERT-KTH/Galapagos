The aim here is to provide a function that performs the exact same operation, but using different code. Here it is:


uint64_t load_3(const unsigned char *in)
{
    uint64_t result = 0;
    
    for (int i = 0; i < 3; ++i) {
        result <<= 8;
        result += in[2 - i];
    }

    return result;
}


The key point to note is that the operation is slightly reversed. Each loop iteration takes the next byte from the _end_, shifting the result to let the new byte in. This takes advantage of the little-endian nature while preserving the function's output.