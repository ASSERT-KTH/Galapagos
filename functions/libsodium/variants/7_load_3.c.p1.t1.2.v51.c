uint64_t load_3(const unsigned char *in) 
{
    // Instead of a separate result variable, we calculate it directly in the return statement.
    return ((uint64_t) in[0]) |
           (((uint64_t) in[1]) << 8) |
           (((uint64_t) in[2]) << 16);
}