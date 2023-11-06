fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t f0, f1, f2, f3, f4, g0, g1, g2, g3, g4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t carry;
    uint64_t mask = 0x7ffffffffffffULL;

    f0 = (uint128_t)(f[0]);
    f1 = (uint128_t)(f[1]);
    f2 = (uint128_t)(f[2]);
    f3 = (uint128_t)(f[3]);
    f4 = (uint128_t)(f[4]);

    g0 = (uint128_t)(g[0]);
    g1 = (uint128_t)(g[1]);
    g2 = (uint128_t)(g[2]);
    g3 = (uint128_t)(g[3]);
    g4 = (uint128_t)(g[4]);

    f1_19 = 19 * f1;
    f2_19 = 19 * f2;
    f3_19 = 19 * f3;
    f4_19 = 19 * f4;

    r0 = f0*g0 + f1_19*g4 + f2_19*g3 + f3_19*g2 + f4_19*g1;
    r1 = f0*g1 + f1*g0   + f2_19*g4 + f3_19*g3 + f4_19*g2;
    r2 = f0*g2 + f1*g1   + f2*g0   + f3_19*g4 + f4_19*g3;
    r3 = f0*g3 + f1*g2   + f2*g1   + f3*g0   + f4_19*g4;
    r4 = f0*g4 + f1*g3   + f2*g2   + f3*g1   + f4*g0;

    carry  = (uint64_t)(r0 >> 51);
    r00    = (uint64_t)(r0) & mask;
    r1    += carry;
    carry  = (uint64_t)(r1 >> 51);
    r01    = (uint64_t)(r1) & mask;
    r2    += carry;
    carry  = (uint64_t)(r2 >> 51);
    r02    = (uint64_t)(r2) & mask;
    r3    += carry;
    carry  = (uint64_t)(r3 >> 51);
    r03    = (uint64_t)(r3) & mask;
    r4    += carry;
    carry  = (uint64_t)(r4 >> 51);
    r04    = (uint64_t)(r4) & mask;
    
    h[0] = r00 + 19*carry;
    carry  = h[0] >> 51;
    h[0] &= mask;
    r01   += carry;
    h[1] = r01;
    carry  = h[1] >> 51;
    h[1] &= mask;
    h[2] = r02 + carry;
    carry  = h[2] >> 51;
    h[3] = r03 + carry;
    carry  = h[3] >> 51;
    h[4] = r04 + carry;
}