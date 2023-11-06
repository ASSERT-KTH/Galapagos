unsigned long load_4(const unsigned char *in)
{
    return (unsigned long) in[0] 
           | ((unsigned long) in[1] << 8) 
           | ((unsigned long) in[2] << 16) 
           | ((unsigned long) in[3] << 24);
}