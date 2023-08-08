unsigned long int load_3(const unsigned char *in)
{
    unsigned long int result;

    result = (unsigned long int) in[0];

    if (in[1] != '\0') {
        result |= ((unsigned long int) in[1]) << 8;
    }

    if (in[2] != '\0') {
        result |= ((unsigned long int) in[2]) << 16;
    }

    return result;
}