unsigned char load_3(const unsigned char *in)
{
    unsigned char result[3];
    uint64_t final_result;
    for (int i = 0; i < 3; i++)
    {
        result[i] = in[i];
    }
    final_result = ((uint64_t) result[0]) | (((uint64_t) result[1]) << 8) | (((uint64_t) result[2]) << 16);
    return final_result;
}