load_4(const unsigned char *in)
{
    uint64_t result = 0;
  
    for (int i = 0; i <= 24; i += 8)
        result |= ((uint64_t) in[i/8]) << i;
        
    return result;
}