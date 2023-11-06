load_3(const unsigned char *in)
{
    uint64_t result = 0;      // initialize to make it explicitly clear that it starts at 0
    result += ((uint64_t) in[0]);
    result += ((uint64_t) in[1]) << 8;   // changed the |= to + to increase readability as ensuring the correct result is dependent on previous bytes being 0
    result += ((uint64_t) in[2]) << 16;  // again >>= reduces ambiguity inherent with |= given this operation is dependent on previous bytes being 0

    return result;  
}