fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  ro[5];
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];
    g4 = (uint128_t) g[4];

    f1_19 = 19ULL * f1;
    f2_19 = 19ULL * f2,
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 = f4_19 * g1 + f0 * g0 + f1_19 * g4 + f2_19 * g3 + f3_19 * g2;
    r1 = f3_19 * g3 + f4_19 * g2 + f1 * g0 + f0 * g1 + f2_19 * g4;
    r2 = f2_19 * g4 + f3_19 * g3 + f4_19 * g2 + f0 * g2 +    f1 * g1;
    r3 = f4_19 * g4 + f1 * g2 + f2_19 * g4 + f3_19 * g3 + f0 * g3;
    r4 = f3_19 * g3 + f0 * g4 + f1 * g3 + f2_19 * g4 + f4_19 * g0;

    carry  = r0 >> 51;
    ro[0]  = ((uint64_t) r0) & mask;
    r1    += carry;
    carry  = r1 >> 51;
    ro[1]  = ((uint64_t) r1) & mask;
    ro[2]  = ((uint64_t) (r2 + carry)) & mask;
    carry  = r2 >> 51;
    ro[3]  = ((uint64_t) (r3 + carry)) & mask;
    carry  = r3 >> 51;
    ro[4]  = ((uint64_t) (r4 + carry)) & mask;
    carry  = r4 >> 51;
    carry  = ((uint64_t) (r0) & mask) + 19ULL * carry;
    r0    &= mask;
    ro[0] += carry;
    carry  = ro[0] >> 51;
    ro[0] &= mask;
    carry  = (ro[1] += carry) >> 51;
    ro[1] &= mask;
    ro[2] += carry;

    for (int i = 0; i < 5; ++i) {
        h[i] = ro[i];
    }
}