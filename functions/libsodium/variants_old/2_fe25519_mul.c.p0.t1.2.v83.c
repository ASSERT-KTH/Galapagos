fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t a1_19, a2_19, a3_19, a4_19;
    uint128_t b0, b1, b2, b3, b4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    a0 = (uint128_t) f[0];
    a1 = (uint128_t) f[1];
    a2 = (uint128_t) f[2];
    a3 = (uint128_t) f[3];
    a4 = (uint128_t) f[4];

    b0 = (uint128_t) g[0];
    b1 = (uint128_t) g[1];
    b2 = (uint128_t) g[2];
    b3 = (uint128_t) g[3];
    b4 = (uint128_t) g[4];

    a1_19 = 19ULL * a1;
    a2_19 = 19ULL * a2;
    a3_19 = 19ULL * a3;
    a4_19 = 19ULL * a4;

    r0 = a0 * b0 + a1_19 * b4 + a2_19 * b3 + a3_19 * b2 + a4_19 * b1;
    r1 = a0 * b1 +    a1 * b0 + a2_19 * b4 + a3_19 * b3 + a4_19 * b2;
    r2 = a0 * b2 +    a1 * b1 +    a2 * b0 + a3_19 * b4 + a4_19 * b3;
    r3 = a0 * b3 +    a1 * b2 +    a2 * b1 +    a3 * b0 + a4_19 * b4;
    r4 = a0 * b4 +    a1 * b3 +    a2 * b2 +    a3 * b1 +    a4 * b0;


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
    r00   += carry * 19ULL;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0]  = r00;
    h[1]  = r01;
    h[2]  = r02;
    h[3]  = r03;
    h[4]  = r04;
}