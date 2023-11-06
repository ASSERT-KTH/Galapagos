unsigned long load_4(const unsigned char *in)
{
    unsigned long result = 0UL;
    unsigned int i;
    for(i=0; i<4; i++)
    {
       result += ((unsigned long) in[i]) << (8*i);
    }
    return result;
}