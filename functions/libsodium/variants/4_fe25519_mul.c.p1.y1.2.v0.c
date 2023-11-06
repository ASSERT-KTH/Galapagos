Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    g0 = 19ULL * (f1 = (uint128_t) f[1]);
    f2_19 = 19ULL * (f2 = (uint128_t) f[2]);
    f3_19 = 19ULL * (f3 = (uint128_t) f[3]);
    f4_19 = 19ULL * (f4 = (uint128_t) f[4]);

    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];
    g4 = (uint128_t) g[4];

    r2 = f0 * g2 + f1   * g1 +    f2 * g0 +   f3_19 * g4 + f4_19 * g3;
    r3 = f0 * g3 + f1   * g2 +    f2 * g1 +       f3 * g0 + f4_19 * g4;
    r4 = f0 * g4 + f1   * g3 +    f2 * g2 +       f3 * g1 +       f4 * g0;
    r0 = f0 * g0 + g0   * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1; 
    r1 = f0 * g1 + f1   * g0 + f2_19 * g4 + f3_19 * g3 + f4_19 * g2;

    r2 += (uint64_t) (carry = (r1 = r1   + (uint64_t) (r0 >>= 51)) >> 51);
    r3 += (uint64_t) (carry = (r2 = r2   & mask) >> 51);
    r4 += (uint64_t) (carry = (r3 = r3   & mask) >> 51);
    r0 = ((h[0] = (r0 & mask) + 19ULL * (carry  = (uint64_t) ((r4 = r4   & mask) >> 51))) >> 51) + (h[1] = (r1 & mask));
    h[2] = r2 + (uint64_t) (carry  = h[0] >> 51);
    h[0] &= mask;
    h[1] += carry;

    h[3] = r3;
    h[4] = r4;
}

Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4, f0, f1, f2, f3, f4, g0, g1, g2, g3, g4;
    uint128_t toMultiplyBy19[] = { 0, (f1 = f[1]) * 19ULL, (f2 = f[2]) * 19ULL,
                            (f3 = f[3]) * 19ULL, (f4 = f[4]) * 19ULL };

    uint64_t rn[] = { 0, 0, 0, 0, (uint64_t)((r4 = (f0 * (g0 = g[0]) + toMultiplyBy19[1] * (g4 = g[4]) +
               toMultiplyBy19[2] * (g3 = g[3]) + toMultiplyBy19[3] * (g2 = g[2]) +
               toMultiplyBy19[4] * (g1 = g[1])) + ((r1 = (f0 * g1 +
               f1 * g0 + toMultiplyBy19[2] * g4 + toMultiplyBy19[3] * g3 + toMultiplyBy19[4] * g2)) >> 51))) >> 51 };

    rn[1] = ((uint64_t)(r2 = (f0 * g2 + f1 * g1 + f2 * g0 + toMultiplyBy19[3] * g4 + toMultiplyBy19[4] * g3) + 
                      ((r0 = ((uint64_t)r0) & mask) >> 51))) >> 51;
    rn[2] = ((uint64_t)(r3 = (f0 * g3 + f1 * g2 + f2 * g1 + f3 * g0 + toMultiplyBy19[4] * g4) + rn[2])) >> 51;
    rn[0] = 19ULL * rn[4];

    h[0] = (uint64_t)r0 + rn[0];
    h[1] = ((uint64_t)r1 + rn[4]) & mask;
    h[4] = (uint64_t)r4 & mask;
    h[3] = ((uint64_t)(r4 = r4 + rn[2]) & mask);
    h[2] = ((uint64_t)(r3 = ((uint64_t)r3) & mask) + (uint64_t)(rn[1] = (h[1] = (h[1] + (h[0] >> 51)) & mask) >> 51 ));
    h[0] &= mask;
}
