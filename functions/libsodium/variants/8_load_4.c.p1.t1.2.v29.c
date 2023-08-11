unsigned char load_4(const unsigned char *in)
{
    unsigned char result;

    for (int i = 0; i < 4; i++) {
        result |= ((unsigned char) in[i]) << (i * 8);
    }

    return result;
}