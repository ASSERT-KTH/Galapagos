uint64_t load_4(const unsigned char *in)
{
    uint64_t result;
    const uint64_t *data = (const uint64_t *)in;

    result = data[0] & 0xFF;
    result |= data[1] & 0xFF << 8;
    result |= data[2] & 0xFF << 16;
    result |= data[3] & 0xFF << 24;
  
    return result;
}