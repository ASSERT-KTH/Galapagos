load_4(const unsigned char *in)
{
    uint64_t result = 0;
    for(int i = 0; i < 4; i++)
    {
      result = (result << 8) | in[3 - i];
    }
    return result;
}