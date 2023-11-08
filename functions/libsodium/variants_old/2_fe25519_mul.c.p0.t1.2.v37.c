fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t f0, f1, f2, f3, f4;
    uint64_t g0, g1, g2, g3, g4;
    uint64_t r00, r01, r02, r03, r04;

    f0 = f[0];
    f1 = f[1];
    f2 = f[2];
    f3 = f[3];
    f4 = f[4];

    g0 = g[0];
    g1 = g[1];
    g2 = g[2];
    g3 = g[3];
    g4 = g[4];

    uint64_t f1_19, f2_19, f3_19, f4_19;
    f1_19 = 19ULL * f1;
    f2_19 = 19ULL * f2;
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    uint128_t r0, r1, r2, r3, r4;
    r0 = ((uint128_t) f0 * g0) + f1_19 * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1;
    r1 = ((uint128_t) f0 * g1) +    f1 * g0 + f2_19 * g4 + f3_19 * g3 + f4_19 * g2;
    r2 = ((uint128_t) f0 * g2) +    f1 * g1 +    f2 * g0 + f3_19 * g4 + f4_19 * g3;
    r3 = ((uint128_t) f0 * g3) +    f1 * g2 +    f2 * g1 +    f3 * g0 + f4_19 * g4;
    r4 = ((uint128_t) f0 * g4) +    f1 * g3 +    f2 * g2 +    f3 * g1 +    f4 * g0;
 
    r00   = r0 & mask; uint64_t carry = (uint64_t) (r0 >> 51); r1 += carry;
    r01   = r1 & mask;                 carry = (r1 >> 51);     r2 += carry;
    r02   = r2 & mask;                 carry = (r2 >> 51);     r3 += carry;
    r03   = r3 & mask;                 carry = (r3 >> 51);     r4 += carry;
    r04   = r4 & mask;                 carry = (r4 >> 51);     r00 += 19ULL * carry;
    r00  &= mask;                      carry = r00 >> 51;      r01 += carry;
    r01  &= mask;                      carry = r01 >> 51;      r02 += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}