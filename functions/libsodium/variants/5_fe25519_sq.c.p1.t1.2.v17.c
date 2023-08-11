void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t tmp[5];
    uint64_t carry;

    uint128_t f0 = (uint128_t) f[0];
    uint128_t f1 = (uint128_t) f[1];
    uint128_t f2 = (uint128_t) f[2];
    uint128_t f3 = (uint128_t) f[3];  
    uint128_t f4 = (uint128_t) f[4];

    tmp[0] = f0 * f0 + 38ULL * f1 * f4 + 38ULL * f2 * f3;
    tmp[1] = (f0 << 1) * f1 + 38ULL * f2 * f4 + 19ULL * f3 * f3;
    tmp[2] = (f0 << 1) * f2 + f1 * f1 + 38ULL * f3 * f4;
    tmp[3] = (f0 << 1) * f3 + (f1 << 1) * f2 + 19ULL * f4 * f4;
    tmp[4] = (f0 << 1) * f4 + (f1 << 1) * f3 + f2 * f2;

    for(int i = 0; i < 4; ++i)
    {
        h[i] = ((uint64_t) tmp[i]) & mask;
        carry = (uint64_t) (tmp[i] >> 51);
        tmp[i+1] += carry;
    }

    h[4] = ((uint64_t) tmp[4]) & mask;
    carry = (uint64_t) (tmp[4] >> 51);
    h[0] += 19ULL * carry;

    for(int i = 0; i < 5; ++i)
    {
        carry  = h[i] >> 51;
        h[i] &= mask;
        if(i < 4) h[i+1] += carry;
    }
}