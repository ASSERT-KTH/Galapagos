unsigned load_3(const unsigned char *in)
{
    unsigned result = 0;

    for (int shift = 0, index = 0; index < 3; ++index, shift += 8)
        result += in[index] << shift;

    return result;
}