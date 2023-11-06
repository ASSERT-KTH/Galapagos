unsigned char load_3(const unsigned char *in)
{
    uint64_t result = 0;
    
    for (int shift = 0; shift <= 16; shift += 8)
    {
        result |= ((uint64_t) *in++) << shift;
    }

    return result;
}