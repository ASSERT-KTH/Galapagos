The below function variant maintains the same function signature and behavior as the original. One behavior modification is to interlace calculations for f1_19, g1, r1 _etc., and also interleaving intermediate result assignments to h[] at different stages of computation.


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t r00, carry;

    f0 = (uint128_t) f[0];
    g0 = (uint128_t) g[0];

    r0 = f0 * g0;
    r00    = (uint64_t) r0 & mask;
    carry  = (uint64_t) (r0 >> 51);
    h[0] = r00;

    f1 = (uint128_t) f[1];
    g1 = (uint128_t) g[1];
    f1_19 = 19ULL * f1;

    r1 = carry + f0 * g1 +    f1_19 * g0;
    r00    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    h[1] = r00;

    f2 = (uint128_t) f[2];
    g2 = (uint128_t) g[2];
    f2_19 = 19ULL * f2;

    r2 = carry + f0 * g2 +    f1 * g1 + f2_19 * g0;
    r00    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    h[2] = r00;

    r3 = carry + f0 * g3 +    f1 * g2 +    f2 * g1 + f3_19 * g0;
    r00    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    h[3] = r00;

    f3 = (uint128_t) f[3];
    g3 = (uint128_t) g[3];
    f3_19 = 19ULL * f3;

    f4 = (uint128_t) f[4];
    g4 = (uint128_t) g[4];
    f4_19 = 19ULL * f4;

    r4 = carry + f0 * g4 +    f1 * g3 +    f2 * g2 +    f3 * g1 +   f4_19 * g0;
    r00    = (uint64_t) r4 & mask;
    carry  = (uint64_t) (r4 >> 51);
    h[4] = r00;

    r00 += 19ULL * carry;
    carry  = r00 >> 51;
    r00 &= mask;
	
    h[0] += carry;
}
