load_4(const unsigned char *in)
{
    uint64_t result;

    for (int i = 0; i < 4; i++)
    {
        result = (result << 8) | in[3 - i];
    }

    return result;
}