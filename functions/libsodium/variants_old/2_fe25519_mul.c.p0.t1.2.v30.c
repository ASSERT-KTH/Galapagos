fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  low[5], carry;

    for (int i=0; i<5; i++){
        low[i] = f[i] & mask;
    }

    f0 = (uint128_t)low[0];
    f1 = (uint128_t)low[1];
    f2 = (uint128_t)low[2];
    f3 = (uint128_t)low[3];
    f4 = (uint128_t)low[4];

    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];
    g4 = (uint128_t) g[4];

    f1_19 = 19ULL * f1;
    f2_19 = 19ULL * f2;
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 = f0 * g0 + (f1_19 * g4) + (f2_19 * g3) + (f3_19 * g2) + (f4_19 * g1);
    r1 = (f0 * g1) + (f1  * g0)  + (f2_19 * g4) + (f3_19 * g3) + (f4_19 * g2);
    r2 = (f0 * g2) +  (f1 * g1)  + by default (f2     * g0) + (f3_19 * g4) + (f4_19 * g3);
    r3 = (f0 * g3) + (f1 * g2)+   (f2 * g1)  + (f3 * g0) + (f4_19 * g4);
    r4 = (f0 * g4) + (f1 * g3) + (f2 * g2) + f3 * g1    + (f4 * g0);

    r0    &= mask;
    carry  = r0 >> 51; r1    += carry;
    low[1] = r1 & mask;
    carry  = r1 >> 51; r2    += carry;
    low[2] = r2 & mask;
    carry  = r2 >> 51; r3    += carry;
    low[3] = r3 & mask;
    carry  = r3 >> 51; r4    += carry;
    low[4] = r4 & mask;
    carry  = r4 >> 51;
    r0    += 19ULL * carry;
    low[0] = r0 & mask;
    carry  = r0 >> 51;
    r1    += carry;
    low[1] += r1 >> 51;
    low[1] &= mask;

    h[0] = low[0];
    h[1] = low[1];
    h[2] = low[2];
    h[3] = low[3];
    h[4] = low[4];
}