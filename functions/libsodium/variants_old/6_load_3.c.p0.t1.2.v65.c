uint64_t load_3(const unsigned char *in)
{
    uint64_t result;
    result = ((uint64_t) *in++) & 0xFF;
    result |= (((uint64_t) *in++) & 0xFF) << 8;
    result |= (((uint64_t) *in) & 0xFF) << 16;

    return result;
}