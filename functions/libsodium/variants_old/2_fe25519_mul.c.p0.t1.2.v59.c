fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g1_m19, g2_m19, g3_m19, g4_m19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    g1_m19 = 19ULL * g[1];
    g2_m19 = 19ULL * g[2];
    g3_m19 = 19ULL * g[3];
    g4_m19 = 19ULL * g[4];

    r0 = f0 * g[0] + f1 * g4_m19 + f2 * g3_m19 + f3 * g2_m19 + f4 * g1_m19;
    r1 = f0 * g[1] + f1 * g[0]  + f2 * g4_m19 +  f3 * g3_m19 +  f4 * g2_m19;
    r2 = f0 * g[2] + f1 * g[1]  + f2 * g[0]   +  f3 * g4_m19 +  f4 * g3_m19;
    r3 = f0 * g[3] + f1 * g[2]  + f2 * g[1]   +  f3 * g[0]   +  f4 * g4_m19;
    r4 = f0 * g[4] + f1 * g[3]  + f2 * g[2]   +  f3 * g[1]   +  f4 * g[0];

    r00    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2    += carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3    += carry;
    r03    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}