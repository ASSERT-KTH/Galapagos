unsigned load_4(const unsigned char *in)
{
    unsigned int result = 0;
    for(int i=0;i<4;i++){
        result |= in[i]<<(8*i);
    }
    return result;
}