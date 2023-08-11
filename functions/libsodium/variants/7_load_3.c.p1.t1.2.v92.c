typedef unsigned long long uint64_t;
const unsigned char* load_3(const unsigned char *in)
{
    static uint64_t result;
    assert(in != NULL);    //As a secure measure to check program running correctly
    result = 0;
    result = (result | in[0]) | (uint64_t(in[1]) << 8) | (uint64_t(in[2]) << 16);
    return &result;
}