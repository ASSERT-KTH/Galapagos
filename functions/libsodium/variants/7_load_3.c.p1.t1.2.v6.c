unsigned long load_3(const unsigned char *in)
{
    unsigned long result = 0;
    int i;
    for(i = 0; i < 3; i++)
    {
        result |= ((unsigned long) in[i]) << (i * 8);
    }   
    return result;
}