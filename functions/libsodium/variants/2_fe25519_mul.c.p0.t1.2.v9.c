fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f[5], g[5];
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    for (int i = 0; i < 5; i++)
    {
        f[i] = (uint128_t) f[i];
        g[i] = (uint128_t) g[i];
    }

    f1_19 = 19ULL * f[1];
    f2_19 = 19ULL * f[2];
    f3_19 = 19ULL * f[3];
    f4_19 = 19ULL * f[4];

    for (uint64_t i = 0; i < 5; i++)
    {      
        uint128_t gg[] = {g[(i+0)%5],g[(i+1)%5],g[(i+2)%5],g[(i+3)%5],g[(i+4)%5]};
        uint128_t ff[] = {f[(i+0)%5],f[(i+1)*19%5],f[(i+2)*19%5],f[(i+3)*19%5],f[(i+4)*19%5]};

        r0 = ff[0] * gg[0] + ff[1] * gg[1] + ff[2] * gg[2] + ff[3] * gg[3] + ff[4] * gg[4];

        uint64_t ri    = ((uint64_t) r0) & mask;
        carry  = (uint64_t) (r0 >> 51);
        r0    += carry;
        ri = ((uint64_t) r0) & mask;
        carry  = (uint64_t) (r0 >> 51);
        ri    += carry;
        ri    -= (ri >> 51) * mask;
        carry  = (uint64_t) (r0 >> 51);
        ri   += 19ULL * carry;
        carry  = ri >> 51;
        ri  &= mask;

        h[i] = ri;
    }
}