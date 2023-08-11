load_4(const unsigned char *in)
{
    uint64_t result;

    ((char*)&result)[0] = in[0];
    ((char*)&result)[1] = in[1];
    ((char*)&result)[2] = in[2];
    ((char*)&result)[3] = in[3];

    return result;
}