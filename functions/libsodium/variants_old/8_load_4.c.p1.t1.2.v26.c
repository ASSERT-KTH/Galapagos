unsigned int load_4(const unsigned char *in)
{
    unsigned int result = 0;

    for (int i=0; i < 4; i++)
    {
        result += ((unsigned int) in[i]) << (8 * i);
    }
    
    return result;
}