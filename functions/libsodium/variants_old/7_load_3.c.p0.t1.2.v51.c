load_3(const unsigned char *in)
{
    uint64_t result = 0;
    for(int i=0; i<3 ;i++)
    {
        result |= ((uint64_t) in[i]) << (i*8);
    }
    return result;
}