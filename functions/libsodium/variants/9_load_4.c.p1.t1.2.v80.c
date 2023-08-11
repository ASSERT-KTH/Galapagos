unsigned long long int load_4(const unsigned char *in)
{
    unsigned long long result;
   
    for (int i = 0; i < 4; i++)
    {
        result |= ((unsigned long long) in[i]) << (8 * i);
    }

    return result;
}