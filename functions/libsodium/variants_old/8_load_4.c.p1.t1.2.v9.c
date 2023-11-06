Here is a different version of the function that will provide the same functionality:


const unsigned char * load_4(const unsigned char *in)
{
    uint64_t result = 0;

    for(int i = 0; i < 4; i++)
    {
        result |= ((uint64_t) in[i]) << (8 * i);
    }

    return result;
}
