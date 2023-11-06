
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    int64_t i = 0;
    const int64_t l = 5;

    while (i < l)
    {
        uint128_t r = 0;
        uint128_t fs = (uint128_t)f[i];
        uint128_t gs = (uint128_t)g[i];

        int64_t j = 0;
        while (j <= i) 
        {
            r += f[j] * g[i - j];
            if (j < i) r += g[j] * f[i - j];
            if (j < i - 1) 
            {
                r += 19ULL * (f[i - j] * g[j + 1] + f[j + 1] * g[i - j]);  
            }
            j += 1; 
        }

        r = r + (r >> 51);
        r = r & ((1ULL << 51) - 1);

        uint64_t carry = r >> 51;
        r = r & mask;
        if (l > i + 1)
        {
            h[i + 1] += carry;
            carry = h[i + 1] >> 51;
            h[i + 1] &= mask;            
        }
        h[i] = r;

        ++i;
    }
}
