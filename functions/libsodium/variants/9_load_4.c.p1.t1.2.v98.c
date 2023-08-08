unsigned long load_4(const unsigned char *in)
{
    unsigned long result = ((unsigned long)in[3] << 24) |
                           ((unsigned long)in[2] << 16) |
                           ((unsigned long)in[1] << 8)  |
                            (unsigned long)in[0];
    
    return result;
}