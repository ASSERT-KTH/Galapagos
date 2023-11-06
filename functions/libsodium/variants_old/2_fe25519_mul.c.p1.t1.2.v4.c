void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], carry;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  carry;

    uint128_t fVals[5] = { f[0], f[1], f[2], f[3], f[4] };
    uint128_t gVals[5] = { g[0], g[1], g[2], g[3], g[4] };
    uint128_t fScaledVals[5] = {
        19ULL * fVals[1],
        19ULL * fVals[2],
        19ULL * fVals[3],
        19ULL * fVals[4]
    };

    for (int i = 0; i < 5; i++)
    {
        r[i] = fVals[0] * gVals[i] + fScaledVals[(5 - i) % 5] * gVals[(4 - i) % 5] + fScaledVals[(4 - i) % 5] * gVals[(3 - i) % 5] + 
               fScaledVals[(3 - i) % 5] * gVals[(2 - i) % 5] + fScaledVals[(2 - i) % 5] * gVals[(1 - i) % 5];

        if (i > 0)
        {
            r[i - 1]    &= mask;
            carry       = (uint64_t) (r[i - 1] >> 51);
            r[i]       += carry;
        }

        h[i] = (uint64_t) r[i];
    }

    carry  = h[4] >> 51;
    h[4]  &= mask;
    h[0]  += 19ULL * carry;
}
