uint64_t load_4(const unsigned char *in)
{
    uint64_t result;
    const unsigned char *local_ptr = in;
    result  = ((uint64_t)*local_ptr++);
    result |= ((uint64_t)*local_ptr++) << 8;
    result |= ((uint64_t)*local_ptr++) << 16;
    result |= ((uint64_t)*local_ptr) << 24;
    return result;
}