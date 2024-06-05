static inline uint64_t fBlaMka(uint64_t x, uint64_t y)
{
    const uint64_t m  = UINT64_C(0xFFFFFFFF);
    const uint64_t xy = (x & m) * (y & m);
    return x + y + 2 * xy;
}