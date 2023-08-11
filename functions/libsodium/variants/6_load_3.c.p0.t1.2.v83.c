load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for (int index = 0; index < 3; index++)
    {
        result |= ((uint64_t) in[index]) << (index * 8);
    }

    return result;
}