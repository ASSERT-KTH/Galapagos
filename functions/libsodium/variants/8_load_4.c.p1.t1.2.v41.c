The below code variant performs exactly the same operation as the original function; the only changes are in line breaks and re-ordering the statements:


load_4(const unsigned char *in)
{
    uint64_t result = (uint64_t) in[0];

    result |= ((uint64_t) in[1]) << 8;

    result |= ((uint64_t) in[2]) << 16;

    result |= ((uint64_t) in[3]) << 24;

    return result;
}
