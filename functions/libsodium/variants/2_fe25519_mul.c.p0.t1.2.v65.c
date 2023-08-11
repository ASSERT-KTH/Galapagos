fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint64_t carry;

    f1_19 = 19ULL * f[1];
    f2_19 = 19ULL * f[2];
    f3_19 = 19ULL * f[3];
    f4_19 = 19ULL * f[4];

    r[0] = f[0] * g[0] + f1_19 * g[4] + f2_19 * g[3] + f3_19 * g[2] + f4_19 * g[1];
    r[1] = f[0] * g[1] + f[1] * g[0] + f2_19 * g[4] + f3_19 * g[3] + f4_19 * g[2];
    r[2] = f[0] * g[2] + f[1] * g[1] + f[2] * g[0] + f3_19 * g[4] + f4_19 * g[3];
    r[3] = f[0] * g[3] + f[1] * g[2] + f[2] * g[1] + f[3] * g[0] + f4_19 * g[4];
    r[4] = f[0] * g[4] + f[1] * g[3] + f[2] * g[2] + f[3] * g[1] + f[4] * g[0];

    for(int i = 0; i < 5; i++)
    {
        h[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);

        if(i+1 < 5)
        {
            r[i+1] += carry;
            h[i] = ((uint64_t) r[i]) & mask;
            carry = (uint64_t) (r[i] >> 51);
        }
    }

    for(int i=0; i < 2; i++)
    {
        h[i] += 19ULL * carry;
        carry  = h[i] >> 51;
        h[i]   &= mask;
    }

    h[2] += carry;
}