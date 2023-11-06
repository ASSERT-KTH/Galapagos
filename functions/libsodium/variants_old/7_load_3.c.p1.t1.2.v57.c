The code variant is:


uint64_t load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for(int i = 0; i < 3; i++)
    {
        result |= ((uint64_t) in[i]) << (8 * i); 
    }

    return result;
}


The original function reads three bytes from `in`, storing the first byte into least significant byte of `result`, continuing with the next bytes.
The variant maintains this behavior but makes use of a loop to accomplish the same task which clarify the pattern the code uses more obvious to the human eye and becomes more scalable if the pattern changed depending on the number of bytes.
