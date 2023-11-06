unsigned short load_3(const unsigned char *in)
{
    unsigned short result = 0;

    for (int i = 0; i < 3; i++)
    {
        result |= ((unsigned short) in[i]) << (8 * i);
    }

    return result;   
}