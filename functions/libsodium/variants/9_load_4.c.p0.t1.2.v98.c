uint64_t load_4(const unsigned char *in)
{
    uint64_t result;
    unsigned int step = 0;
    while(step < 4)
    {
        result |= ((uint64_t) in[step]) << (step * 8);
        step++;
    }
    return result;
}