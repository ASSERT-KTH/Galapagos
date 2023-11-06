
uint64_t load_3(const unsigned char *in) 
{
    uint64_t result = 0;
    for (int i = 0; i < 3; ++i) 
    {
        result |= ((uint64_t) in[i]) << (i * 8);
    }
    return result;
}

This version of program keeps the same functionality with the original function. The behavior of the function is changed slightly in a way that it employs a for loop to achieve the result rather than using a straightforward assignments. Consequently, this will introduce a slight increase in running performance overhead due to loop execution, while reducing repetition in operations and contributing to code brevity.