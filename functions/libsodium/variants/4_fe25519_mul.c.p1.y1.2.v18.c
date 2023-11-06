Variant 1: Reordering of computations


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    g0 = (uint128_t) g[0];

    f1 = (uint128_t) f[1];
    g1 = (uint128_t) g[1];
    f1_19 = 19ULL * f1;

    f2 = (uint128_t) f[2];
    g2 = (uint128_t) g[2];
    f2_19 = 19ULL * f2;

    f3 = (uint128_t) f[3];
    g3 = (uint128_t) g[3];
    f3_19 = 19ULL * f3;

    f4 = (uint128_t) f[4];
    g4 = (uint128_t) g[4];
    f4_19 = 19ULL * f4;

    r0 = f0 * g0 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1 + f1_19 * g4;
    r1 = f0 * g1 + f2_19 * g4 +    f1 * g0 + f3_19 * g3 + f4_19 * g2;
    r2 = f0 * g2 +    f1 * g1 + f3_19 * g4 +    f2 * g0 + f4_19 * g3;
    r3 = f0 * g3 +    f1 * g2 +    f3 * g0 +    f2 * g1 + f4_19 * g4;
    r4 = f0 * g4 +    f1 * g3 +    f2 * g2 +    f3 * g1 +    f4 * g0;

    carryReduction(&r0, &r1, &r2, &r3, &r4);

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}


Variant 2: Batching assignments


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];

    r0 = f0 * g0 + f1 * g1 * 19;
    r1 = f0 * g1 + f1 * g0;

    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];

    r0 += f2 * g2 * (...etc, complete accordingly by following the same pattern)
}
