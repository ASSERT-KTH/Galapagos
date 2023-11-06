load_4(const unsigned char *in)
{
    uint64_t result;

    if(in)
    {
        result = ((uint64_t) in[0]) | 
                 ((uint64_t) in[1]) << 8  | 
                 ((uint64_t) in[2]) << 16 | 
                 ((uint64_t) in[3]) << 24;
    } 
    else 
    {
        result = 0;
    }

    return result;
}