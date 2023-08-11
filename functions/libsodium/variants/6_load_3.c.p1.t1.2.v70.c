uint64_t load_3(const unsigned char *in)
{
    uint64_t result;
  
    result = (in[0] | (in[1] << 8) | (in[2] << 16));

    return result;
}