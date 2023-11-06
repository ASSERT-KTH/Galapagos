The following is a variant of the original function that maintains the same functionality.


load_3(const unsigned char *in) 
{
    uint64_t result = 0;
    int i;

    for(i = 0; i < 3; i++)
    {
        result |= ((uint64_t) in[i]) << (8 * i);
    }
    
    return result;
}


In this code, a for loop has been used as alternative to directly copying and shifting the bytes one by one. The result will be the same. It is to be noted that in this scenario, this variant is useful if the byte length was uncertain or might change in the future.